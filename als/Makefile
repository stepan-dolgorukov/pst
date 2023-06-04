CXX:=/usr/bin/clang++
CC:=/usr/bin/clang

als: test.o als.o eq.o
	$(CXX) test.o als.o eq.o -o als

test.o: test.cxx
	$(CXX) -c test.cxx -o test.o

als.o: als.c
	$(CC) -c als.c -o als.o

eq.o: eq.c
	$(CC) -c eq.c -o eq.o
