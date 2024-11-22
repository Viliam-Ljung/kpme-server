CC=gcc

empty:=
space:=$(empty) $(empty)
comma:=$(space)-I

SRC=src
BIN=bin
INCLUDE=$(subst $(space),$(comma),$(space)$(shell find -name "include" -type d))

SOURCES=$(shell find -path "*/$(SRC)/*" -type f)

CFLAGS=-Wall $(INCLUDE)

all: binaries 

binaries: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $(BIN)/main
