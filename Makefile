CXX:=/usr/bin/clang++
CC:=/usr/bin/clang

als: main.o als.o eq.o
	$(CXX) main.o als.o eq.o -o als

test.o: test.cxx
	$(CXX) -c test.cxx -o main.o

als.o: als.c
	$(CC) -c als.c -o als.o

eq.o: eq.c
	$(CC) -c eq.c -o eq.o
