# GLOBAL CFLAGS
AM_CFLAGS   = -coverage -O2 -Wall
AM_CXXFLAGS = $(CFLAGS)

bin_PROGRAMS = phex
phex_SOURCES = src/main.c src/print.c src/hex.c src/string.c
phex_CLAGSS = -O0
EXTRA_DIST = docs man

TESTS = tests/simple.sh tests/complex.sh tests/error.sh
