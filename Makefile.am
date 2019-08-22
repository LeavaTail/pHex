# GLOBAL CFLAGS
AM_CFLAGS   = -coverage -O2 -Wall
AM_CXXFLAGS = $(CFLAGS)

bin_PROGRAMS = phex
phex_SOURCES = src/main.c src/print.c src/hex.c src/string.c
phex_CFLAGS = -O0 -g -coverage -Wall
EXTRA_DIST = docs man

man_MANS = man/phex.1
TESTS = tests/simple.sh tests/complex.sh tests/error.sh
