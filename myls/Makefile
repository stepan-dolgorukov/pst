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
			file_modif_time.o \
			file_info.o

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
	file_info.o \
	-o myls

myls.o: myls.cxx
	$(CXX) -c myls.cxx -o myls.o

argparser.o: argparser.cxx argparser.hxx
	$(CXX) -c argparser.cxx -o argparser.o

mode.o: mode.cxx mode.hxx
	$(CXX) -c mode.cxx -o mode.o

option_mask.o: option_mask.cxx option_mask.hxx
	$(CXX) -c option_mask.cxx -o option_mask.o

file_perm.o: file_perm.cxx file_perm.hxx
	$(CXX) -c file_perm.cxx -o file_perm.o

file_type.o: file_type.cxx file_type.hxx
	$(CXX) -c file_type.cxx -o file_type.o

file_size.o: file_size.cxx file_size.hxx
	$(CXX) -c file_size.cxx -o file_size.o

file_hlinks_amnt.o: file_hlinks_amnt.cxx file_hlinks_amnt.hxx
	$(CXX) -c file_hlinks_amnt.cxx -o file_hlinks_amnt.o

file_owner.o: file_owner.cxx file_owner.hxx
	$(CXX) -c file_owner.cxx -o file_owner.o

file_modif_time.o: file_modif_time.cxx file_modif_time.hxx
	$(CXX) -c file_modif_time.cxx -o file_modif_time.o

file_info.o: file_info.cxx file_info.hxx
	$(CXX) -c file_info.cxx -o file_info.o