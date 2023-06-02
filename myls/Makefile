CXX := /usr/bin/g++

myls: myls.o argparser.o mode.o mode_mask.o
	$(CXX) myls.o argparser.o mode.o mode_mask.o -o myls

myls.o: myls.cxx
	$(CXX) -c myls.cxx -o myls.o

argparser.o: argparser.cxx
	$(CXX) -c argparser.cxx -o argparser.o

mode.o: mode.cxx
	$(CXX) -c mode.cxx -o mode.o

mode_mask.o: mode_mask.cxx
	$(CXX) -c mode_mask.cxx -o mode_mask.o