CXX := /usr/bin/g++

myls: myls.o argparser.o mode.o
	$(CXX) myls.o argparser.o mode.o -o myls

myls.o: myls.cxx
	$(CXX) -c myls.cxx -o myls.o

argparser.o: argparser.cxx
	$(CXX) -c argparser.cxx -o argparser.o

mode.o: mode.cxx
	$(CXX) -c mode.cxx -o mode.o