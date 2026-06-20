# tree-sitter-folio

A [tree-sitter](https://tree-sitter.github.io/) grammar for **folio**, the
dialogue/scripting layer over [lish](https://github.com/mhogle25/lish). It
highlights folio's outer structure (scenes, beats, comments, dialogue, sigils)
and **injects the lish grammar** into embedded `{...}` blocks, so the lish inside
gets the same highlighting as a standalone `.lish` file.

## The folio surface this grammar models

```folio
// a line comment

::main                              -- scene header
#"Stranger:"                        -- instant string (a speaker label)
I just need{ delay medium } here.   -- dialogue text with an inline { lish } block
;;                                  -- beat break
%{ scene market }                   -- deferred lish block
```

- **Scenes** `::name`, **beats** `;;`, **comments** `//` (distinct from lish's `##`).
- **Blocks** of embedded lish: `{ }` plain, `#{ }` instant, `%{ }` deferred,
  `@{ }` character. Their content is the `block_body` node, re-parsed as lish.
- **Sigil strings**: `#"..."` / `@"..."`. The `#`/`%`/`@` sigils are
  context-sensitive (a sigil only when it prefixes a block or string), and
  `::`/`;;`/`//` are structural only at the start of a line.

## External scanner

Two tokens need an external scanner (`src/scanner.c`) because folio's lexing is
context sensitive in ways a regex cannot express:

- **`text`** mirrors `folio/src/lexer.zig`'s `scanPlainText`.
- **`block_body`** mirrors `lish/src/boundary.zig`'s brace boundary (`open='{'`):
  depth-tracked, skipping a `}` inside a lish string or `##` comment. A streaming
  tree-sitter scanner cannot link the Zig boundary finder, so it keeps its own
  scan, **held to the shared corpus** (`lish/src/scanner_corpus/`, the `}` cases)
  by `test/scanner-corpus.test.js`.

## Generated constants (no drift)

The grammar and scanner never hand-mirror folio's character constants. folio owns
the source of truth (`folio/src/token.zig`) and emits `constants.{js,h}` via
`zig build gen`; `scripts/sync.js` vendors them into `common/`, which `grammar.js`
(`require('./common/constants')`) and `scanner.c` (`#include "../common/constants.h"`)
consume. CI guards both levels with a `git diff` check, mirroring tree-sitter-lish.

## Building and testing

```sh
pnpm install            # also vendors common/ via the postinstall sync
pnpm run generate       # tree-sitter generate
pnpm test               # corpus tests + the shared scanner-boundary contract
```

`scripts/sync.js` resolves the folio source via the `FOLIO_SOURCE` env var or
`.foliosource.json` (`../folio`), and folio in turn pins lish at `../lish`, so the
three repos clone side by side.

## Editor integration

`injection-regex` and `injections.scm` make embedded `{...}` blocks re-parse as
`lish`, so a `lish` parser must also be installed for the inner highlighting.

For Neovim (core `vim.treesitter`, locally-developed grammar), compile the parser
into the data dir and load the queries from this repo:

```sh
tree-sitter build -o ~/.local/share/nvim/site/parser/folio.so
```

then register the `.folio` filetype, set the `folio` queries, and start
treesitter on `FileType folio` (see the lish/folio nvim config for the pattern).
