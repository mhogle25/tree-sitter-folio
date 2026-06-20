; Re-parse every `{...}` block body with the lish grammar, so embedded lish
; gets the same highlighting as a standalone .lish file.

((block_body) @injection.content
 (#set! injection.language "lish"))
