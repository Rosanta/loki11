CC=g++
CFLAGS=--std=c++11 -I/usr/local/include -I../ $(LIBS) -g
LIBS= /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a /usr/local/lib/libglog.a

.PHONY : all

typelist : all
	$(CC) $(CFLAGS) typelist.cc -o typelist && ./typelist

hierarchy : all
	$(CC) $(CFLAGS) hierarchy_generator.cc -o hierarchy_generator && ./hierarchy_generator

tuple : all
	$(CC) $(CFLAGS) tuple.cc -o tuple && ./tuple

functor : all
	$(CC) $(CFLAGS) functor.cc -o functor && ./functor

test : typelist hierarchy tuple functor
