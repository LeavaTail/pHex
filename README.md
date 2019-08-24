# pHex
[![Build Status](https://travis-ci.org/LeavaTail/pHex.svg?branch=master)](https://travis-ci.org/LeavaTail/pHex)
[![codecov](https://codecov.io/gh/LeavaTail/pHex/branch/master/graph/badge.svg)](https://codecov.io/gh/LeavaTail/pHex)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/92896c427d5e4520863485ce76dfa791)](https://www.codacy.com/app/LeavaTail/pHex?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=LeavaTail/pHex&amp;utm_campaign=Badge_Grade)

`phex`(Print HEXadecimal) make a hexdump or do the reverse that referenced `xxd`.

## Description
`phex` creates a hex dump of a given file or standard input.
It can also convert a hex dump back to its original binary form.
Like `uuencode`(1) and `uudecode`(1) it allows the transmission of binary data in a 'mail-safe' ASCII representation, but has the advantage of decoding to standard output.

***DEMO:***
```
  $ phex AUTHORS
00000000:4c65 6176 6154 6169 6c20 3c73 7461 626f LeavaTail.<stabo
00000010:772e 6475 7374 6572 4067 6d61 696c 2e63 w.duster@gmail.c
00000020:6f6d 3e0a 0000 0000 0000 0000 0000 0000 om>.
```

## Requirement

- Autoconf  <http://www.gnu.org/software/autoconf/>
- Automake  <http://www.gnu.org/software/automake/>
- Git       <http://git.or.cz/>

## Installation

1. Generate configure file. `./script/bootstrap.sh`
2. Configure the package for your system. `./configure`
3. Compile the package. `make`
4. Install the program. `make install`

## Authors

[LeavaTail](https://github.com/LeavaTail)

## License

[MIT](./LICENSE)
