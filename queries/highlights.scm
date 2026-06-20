; Highlights for folio.

(comment) @comment @spell

; Scene headers: `::name`
(scene_header) @keyword
(scene_name) @function

; Beat breaks: `;;`
(beat_break) @punctuation.special

; Dialogue text is intentionally left uncaptured: it renders as plain prose
; (default foreground), markdown-style, so only the structure (scenes, beats,
; sigils) and the embedded lish stand out.

; Sigil-prefixed strings (`#"..."`, `@"..."`): labels / character names. The
; quoted part gets the distinct "special string" shade; the leading sigil stays
; punctuation.
(double_string) @string.special
(single_string) @string.special

; Block delimiters and sigils are punctuation; the lish inside is highlighted by
; the injected grammar.
[
  "{"
  "}"
  "#{"
  "%{"
  "@{"
] @punctuation.bracket

[
  "#"
  "@"
] @punctuation.special
