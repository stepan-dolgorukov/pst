CXX := /usr/bin/g++
CXXFLAGS := -pedantic -Wall -Wextra -std=c++11

myls: myls.o \
			argparser.o \
			mode.o \
			options_storage.o \
			file_perm.o \
			file_type.o \
			file_size.o \
			file_hlinks_amnt.o \
			file_owner.o \
			file_modif_time.o \
			file_info.o \
			former.o \
			formatter.o

	$(CXX) \
	myls.o \
	argparser.o \
	mode.o \
	options_storage.o \
	file_perm.o \
	file_type.o \
	file_size.o \
	file_hlinks_amnt.o \
	file_owner.o \
	file_modif_time.o \
	file_info.o \
	former.o \
	formatter.o \
	-o myls

myls.o: myls.cxx
	$(CXX) $(CXXFLAGS) -c myls.cxx -o myls.o

argparser.o: argparser.cxx \
						 argparser.hxx
	$(CXX) $(CXXFLAGS) -c argparser.cxx -o argparser.o

mode.o: mode.cxx \
				mode.hxx
	$(CXX) $(CXXFLAGS) -c mode.cxx -o mode.o

options_storage.o: options_storage.cxx \
									 options_storage.hxx
	$(CXX) $(CXXFLAGS) -c options_storage.cxx -o options_storage.o

file_perm.o: file_perm.cxx \
						 file_perm.hxx
	$(CXX) $(CXXFLAGS) -c file_perm.cxx -o file_perm.o

file_type.o: file_type.cxx \
						 file_type.hxx
	$(CXX) $(CXXFLAGS) -c file_type.cxx -o file_type.o

file_size.o: file_size.cxx \
						 file_size.hxx
	$(CXX) $(CXXFLAGS) -c file_size.cxx -o file_size.o

file_hlinks_amnt.o: file_hlinks_amnt.cxx \
										file_hlinks_amnt.hxx
	$(CXX) $(CXXFLAGS) -c file_hlinks_amnt.cxx -o file_hlinks_amnt.o

file_owner.o: file_owner.cxx \
							file_owner.hxx
	$(CXX) $(CXXFLAGS) -c file_owner.cxx -o file_owner.o

file_modif_time.o: file_modif_time.cxx \
									 file_modif_time.hxx
	$(CXX) $(CXXFLAGS) -c file_modif_time.cxx -o file_modif_time.o

file_info.o: file_info.cxx \
						 file_info.hxx
	$(CXX) $(CXXFLAGS) -c file_info.cxx -o file_info.o

former.o: former.cxx \
					former.hxx
	$(CXX) $(CXXFLAGS) -c former.cxx -o former.o

formatter.o: formatter.cxx \
						 formatter.hxx
	$(CXX) $(CXXFLAGS) -c formatter.cxx -o formatter.o