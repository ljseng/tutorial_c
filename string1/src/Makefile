CC=gcc
MAIN=main.c
DBGFLAGS=-g
BIN=../bin/main.out
BINDBG=../bin/main.dbg.out

all:
	$(CC) $(MAIN) -o $(BIN)

debug:
	$(CC) $(DBGFLAGS) $(MAIN) -o $(BINDBG)

run:
	$(BIN)

clean:
	rm -f $(BIN) $(BINDBG)
