CC=clang++
CFLAGS=--std=c++11 -I/usr/local/include -I ../ $(SLIBS)
SLIBS=/usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a

.PHONY : all

typelist : all
	$(CC) $(CFLAGS) typelist.cc -o typelist && ./typelist

hierarchy : all
	$(CC) $(CFLAGS) hierarchy_generator.cc -o hierarchy_generator && ./hierarchy_generator


test : typelist hierarchy
