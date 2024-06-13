# Notes

`-O.`
`# +`

> 2 If there are insufficient arguments for the format, the behavior is
> undefined. If the format is exhausted while arguments remain, the excess
> arguments are evaluated (as always) but are otherwise ignored.

> 9 If a conversion specification is invalid, the behavior is undefined.239) If
> any argument is not the correct type for the corresponding conversion
> specification, the behavior is undefined.

sequence:

- Zero or more flags (in any order)
- An optional minimum field width. If the converted value has fewer characters
  than the field width, it is padded with spaces (by default) on the left (or
  right, if the left adjustment flag, described later, has been given) to the
  field width. The field width takes the form of an asterisk * (described
  later) or a decimal integer
- An optional precision that gives the minimum number of digits to appear for
  the d, i, o, u, x, and X conversions, or the maximum number of bytes to be
  written for s conversions. The precision takes the form of a period (.)
  followed either by an asterisk * (described later) or by an optional decimal
  integer; if only the period is specified, the precision is taken as zero. If
  a precision appears with any other conversion specifier, the behavior is
  undefined.
- (An optional length modifier that specifies the size of the argument. eg zu)
- A conversion specifier character that specifies the type of conversion to be
  applied.


conversion specifiers:

- d, i int
    - The precision specifies the minimum number of digits to appear (default 1)
    - The result of converting a zero value with a precision of zero is no
      characters.
- u, X, x unsigned int
    - same
- c
    - If no l length modifier is present, the int argument is converted to an
      unsigned char, and the resulting character is written. If an l length
      modifier is present, the wint_t argument is converted as if by an ls
      conversion specification with no precision and an argument that points to
      the initial element of a two-element array of wchar_t, the first element
      containing the wint_t argument to the lc conversion specification and the
      second a null wide character.
- s
    - If the precision is specified, no more than that many bytes are written.
- p
- %


> 14 The fprintf function returns the number of characters transmitted, or a
> negative value if an output or encoding error occurred.
