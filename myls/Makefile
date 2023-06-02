CXX := /usr/bin/g++

myls: myls.o argparser.o mode.o option_mask.o file_perm.o
	$(CXX) myls.o argparser.o mode.o option_mask.o file_perm.o -o myls

myls.o: myls.cxx
	$(CXX) -c myls.cxx -o myls.o

argparser.o: argparser.cxx
	$(CXX) -c argparser.cxx -o argparser.o

mode.o: mode.cxx
	$(CXX) -c mode.cxx -o mode.o

option_mask.o: option_mask.cxx
	$(CXX) -c option_mask.cxx -o option_mask.o

file_perm.o: file_perm.cxx
	$(CXX) -c file_perm.cxx -o file_perm.o