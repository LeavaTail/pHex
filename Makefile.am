# GLOBAL CFLAGS
AM_CFLAGS   = -O2 -Wall
AM_CXXFLAGS = $(CFLAGS)

bin_PROGRAMS = phex
phex_SOURCES = src/main.c src/print.c src/hex.c src/string.c
if DEBUG
phex_CFLAGS = -O0 -g3 -coverage -Wall -DPHEX_DEBUG
else
phex_CFLAGS = -O2
endif

EXTRA_DIST = docs man
man_MANS = man/phex.1
TESTS = tests/simple.sh tests/complex.sh tests/error.sh
