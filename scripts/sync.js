#!/usr/bin/env node
// ---------------------------------------------------------------------------
// Vendors folio's generated cross-language artifacts into common/.
//
// folio owns the source of truth (src/token.zig) and emits the mirrors this
// grammar consumes (constants.js, constants.h) via `zig build gen`. This script
// pulls those in so the grammar and external scanner never hand-mirror folio's
// character constants. Mirrors tree-sitter-lish/scripts/sync.js.
//
// Source resolution precedence:
//   1. FOLIO_SOURCE env var          path to a folio checkout
//   2. .foliosource.json { "path" }  relative to this repo's root
//   3. error                         (downgraded to a warning under --soft)
//
// When the resolved source is a local checkout with `zig` on PATH, the script
// runs `zig build gen` first so the vendored copies are fresh. Otherwise it
// copies whatever the source already has under generated/.
// ---------------------------------------------------------------------------

const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const REPO_ROOT = path.join(__dirname, '..');
const SOURCE_PIN = path.join(REPO_ROOT, '.foliosource.json');
const COMMON_DIR = path.join(REPO_ROOT, 'common');

// Files to vendor: generated name -> destination under common/.
const ARTIFACTS = {
    'constants.js': 'constants.js',
    'constants.h': 'constants.h',
};

const soft = process.argv.includes('--soft');

function note(message) {
    console.log('sync: ' + message);
}

function bail(message) {
    if (soft) {
        console.warn('sync: skipped (' + message + ')');
        process.exit(0);
    }
    console.error('sync FAILED: ' + message);
    process.exit(1);
}

function resolveSource() {
    if (process.env.FOLIO_SOURCE) {
        return path.resolve(process.env.FOLIO_SOURCE);
    }
    if (fs.existsSync(SOURCE_PIN)) {
        const pin = JSON.parse(fs.readFileSync(SOURCE_PIN, 'utf8'));
        if (pin.path) return path.resolve(REPO_ROOT, pin.path);
        bail(`.foliosource.json has no "path" key`);
    }
    bail('no folio source configured (set FOLIO_SOURCE or create .foliosource.json)');
}

function regenerate(sourceDir) {
    if (!fs.existsSync(path.join(sourceDir, 'build.zig'))) return;
    const zig = spawnSync('zig', ['build', 'gen'], { cwd: sourceDir, stdio: 'inherit' });
    if (zig.error || zig.status !== 0) {
        console.warn('sync: could not run `zig build gen` in source; using committed generated files');
    }
}

const sourceDir = resolveSource();
const generatedDir = path.join(sourceDir, 'generated');

regenerate(sourceDir);

if (!fs.existsSync(generatedDir)) {
    bail(`no generated/ directory in source: ${sourceDir} (run \`zig build gen\` there)`);
}

fs.mkdirSync(COMMON_DIR, { recursive: true });
const copied = [];
for (const [from, to] of Object.entries(ARTIFACTS)) {
    const src = path.join(generatedDir, from);
    if (!fs.existsSync(src)) bail(`missing generated artifact: ${src}`);
    fs.copyFileSync(src, path.join(COMMON_DIR, to));
    copied.push(to);
}

note(`vendored ${copied.join(', ')} from ${sourceDir}`);
