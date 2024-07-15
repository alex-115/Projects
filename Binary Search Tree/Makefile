# Makefile 
# Commands all have the following format:
#    file_to_be_created: list_of_files_the_file_to_left_is_create_from
#    <tab>the command that generates this file
#
# Compiler options
#    the arguments after g++ specify specific options for the compiler
#    -Wall        ==> print all warnings
#    -pedantic    ==> print warnings when non-standard C++ is used
#    -g           ==> keep additional information to aid in debugging
#    -o           ==> specify the output filename
#    -c           ==> compile only (create a .o file)
#    -std=c++11   ==> use the C++11 standard

bst: main.o bst.o
	g++ -Wall -pedantic -g -o bst main.o bst.o

bst.o: bst.cpp bst.h
	g++ -Wall -pedantic -g -std=c++11 -c bst.cpp

main.o: main.cpp bst.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

clean:
	rm -f bst bst.exe bst.o main.o
