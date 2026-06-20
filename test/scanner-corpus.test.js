// ---------------------------------------------------------------------------
// Runs the shared scanner-boundary corpus against the tree-sitter folio
// external scanner.
//
// The corpus lives in ../../lish/src/scanner_corpus/ -- the same one consumed by
// lish's lexer test, lish/src/boundary.zig's test, and tree-sitter-lish's `|`
// scanner test. See its README for the file format and the contract every
// embedder is held to. This file exercises the `}` (brace) cases, which belong
// to folio's block-body scanner (tree-sitter-lish runs the `|` cases).
//
// For each `}` case, we synthesize a folio document that wraps the case source
// as the body of a `{...}` block, shell out to `tree-sitter parse`, extract the
// block_body node's end position, convert it to a byte offset within the
// original source, and assert it equals the declared boundary. A streaming
// tree-sitter scanner can't call lish's shared boundary finder (boundary.zig),
// so this proves folio's own scan agrees with it.
// ---------------------------------------------------------------------------

const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const CORPUS_DIR = path.join(__dirname, '..', '..', 'lish', 'src', 'scanner_corpus');
const GRAMMAR_DIR = path.join(__dirname, '..');
const TREE_SITTER = process.env.TREE_SITTER
    || path.join(GRAMMAR_DIR, 'node_modules', '.bin', 'tree-sitter');

function parseCase(text) {
    const sepIdx = text.indexOf('---\n');
    if (sepIdx < 0) throw new Error('case missing --- separator');
    const header = text.slice(0, sepIdx);
    let source = text.slice(sepIdx + 4);
    if (source.endsWith('\n')) source = source.slice(0, -1);

    const meta = {};
    for (const line of header.split('\n')) {
        const m = line.match(/^([a-z_]+):\s*(.+)$/);
        if (m) meta[m[1]] = m[2];
    }
    return {
        terminator: meta.terminator,
        boundary: parseInt(meta.boundary, 10),
        source,
    };
}

// Convert a [line, column] position (0-indexed, tree-sitter style) into a byte
// offset within `source`. ASCII corpus, so a straight count.
function lineColToByte(source, line, col) {
    if (line === 0) return col;
    let pos = 0;
    for (let i = 0; i < line; i++) {
        pos = source.indexOf('\n', pos);
        if (pos < 0) throw new Error(`source has only ${i + 1} lines, asked for line ${line}`);
        pos += 1;
    }
    return pos + col;
}

function parseWithFolio(source) {
    const tmp = path.join('/tmp', `tree-sitter-folio-${process.pid}-${Date.now()}.folio`);
    fs.writeFileSync(tmp, source);
    try {
        const result = spawnSync(TREE_SITTER, ['parse', tmp], {
            cwd: GRAMMAR_DIR,
            encoding: 'utf8',
        });
        if (result.status !== 0 && result.status !== 1) {
            // 0 = clean parse, 1 = parse with errors (still produces a tree).
            throw new Error(`tree-sitter parse exited ${result.status}: ${result.stderr}`);
        }
        return result.stdout;
    } finally {
        fs.unlinkSync(tmp);
    }
}

// The first block_body node's end [line, col]. Lines look like:
//   (block_body [1, 1] - [1, 23])
function findBlockBodyEnd(parseOutput) {
    const m = parseOutput.match(/block_body\s*\[\d+,\s*\d+\]\s*-\s*\[(\d+),\s*(\d+)\]/);
    if (!m) return null;
    return [parseInt(m[1], 10), parseInt(m[2], 10)];
}

function fail(message) {
    console.error('scanner-corpus FAILED:\n  ' + message);
    process.exit(1);
}

// Each case's source is the RAW lish content inside a block, including the
// terminating `}` and whatever follows it. Wrap it as a block body in a minimal
// scene/beat so tree-sitter-folio parses it:
//
//     ::x\n{<source>\n;;\n
//
// The block_body's end position in the synthesized parse, minus the prefix
// length, is the boundary within the original source.
const WRAPPER_PREFIX = '::x\n{';
const WRAPPER_SUFFIX = '\n;;\n';

const files = fs.readdirSync(CORPUS_DIR).filter(f => f.endsWith('.case')).sort();
const errors = [];
let braceCount = 0;

for (const filename of files) {
    const text = fs.readFileSync(path.join(CORPUS_DIR, filename), 'utf8');
    const c = parseCase(text);
    if (c.terminator !== '}') continue;
    braceCount += 1;

    const synth = WRAPPER_PREFIX + c.source + WRAPPER_SUFFIX;
    const output = parseWithFolio(synth);
    const end = findBlockBodyEnd(output);
    if (!end) {
        errors.push(
            `${filename}: no block_body node in parse output\n    synth: ${JSON.stringify(synth)}`,
        );
        continue;
    }

    const synthOffset = lineColToByte(synth, end[0], end[1]);
    const actual = synthOffset - WRAPPER_PREFIX.length;
    if (actual !== c.boundary) {
        errors.push(
            `${filename}: expected boundary ${c.boundary}, scanner reports ${actual}\n` +
            `    source: ${JSON.stringify(c.source)}\n` +
            `    block_body end position: [${end[0]}, ${end[1]}] (offset ${synthOffset} in synth)`,
        );
    }
}

if (errors.length > 0) fail('\n  ' + errors.join('\n  '));
if (braceCount === 0) fail('no `}` cases found in corpus -- did the path move?');

console.log(`scanner-corpus OK (${braceCount} cases verified)`);
