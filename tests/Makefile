CC=clang++
CFLAGS=--std=c++11 -I/usr/local/include -I ../ $(LIBS)
LIBS=-lgtest -lgtest_main

.PHONY : all

typelist : all
	$(CC) $(CFLAGS) typelist.cc -o typelist && ./typelist

hierarchy : all
	$(CC) $(CFLAGS) hierarchy_generator.cc -o hierarchy_generator && ./hierarchy_generator

tuple : all
	$(CC) $(CFLAGS) tuple.cc -o tuple && ./tuple

test : typelist hierarchy tuple
