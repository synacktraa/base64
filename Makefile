
BIN=gcc
CFLAGS=-g -Wall

all: base_64

base64.o: base64.c
	$(BIN) $(CFLAGS) -c $^

base64_utils.o: base64_utils.c base64_utils.h
	$(BIN) $(CFLAGS) -c $^

base_64: base64.o base64_utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:
	rm *.o base_64