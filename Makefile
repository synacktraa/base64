
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

ifeq ($(OS),Windows_NT)
	del *.o base_64.exe *.gch 
else
	CHECK := $(shell uname)
	ifeq ($(CHECK), Linux)
		rm *.o base_64 *.gch
	endif
endif