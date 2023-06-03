CXX := /usr/bin/g++

myls: myls.o \
			argparser.o \
			mode.o \
			option_mask.o \
			file_perm.o \
			file_type.o \
			file_size.o \
			file_hlinks_amnt.o \
			file_owner.o \
			file_modif_time.o

	$(CXX) \
	myls.o \
	argparser.o \
	mode.o \
	option_mask.o \
	file_perm.o \
	file_type.o \
	file_size.o \
	file_hlinks_amnt.o \
	file_owner.o \
	file_modif_time.o \
	-o myls

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

file_type.o: file_type.cxx
	$(CXX) -c file_type.cxx -o file_type.o

file_size.o: file_size.cxx
	$(CXX) -c file_size.cxx -o file_size.o

file_hlinks_amnt.o: file_hlinks_amnt.cxx
	$(CXX) -c file_hlinks_amnt.cxx -o file_hlinks_amnt.o

file_owner.o: file_owner.cxx
	$(CXX) -c file_owner.cxx -o file_owner.o

file_modif_time.o: file_modif_time.cxx
	$(CXX) -c file_modif_time.cxx -o file_modif_time.o