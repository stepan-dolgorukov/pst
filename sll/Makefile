CC:=/usr/bin/clang
CXX:=/usr/bin/clang++

sll_test: test.o sll.o
	$(CXX) test.o sll.o -o sll_test

sll.o: sll.c
	$(CC) -c sll.c -o sll.o

test.o: test.cxx
	$(CXX) -c test.cxx -o test.o
