CC = gcc
CFLAGS = -O0
CPPFLAGS = -O0
CPPC = g++

all: c-bench cpp-bench
	@echo "Done!"

c-bench: c-bench.c
	$(CC) $(CFLAGS) -o $@ $?

cpp-bench: cpp-bench.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $?
