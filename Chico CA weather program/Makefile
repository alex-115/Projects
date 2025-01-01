# Makefile for 211 weather program assignment
ADT: data.o main.o ADT.o
	 g++ -Wall -pedantic -g -o ADT data.o main.o ADT.o

main.o: main.cpp data.h ADT.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

data.o: data.h data.cpp
	g++ -Wall -pedantic -g -std=c++11 -c data.cpp

ADT.o: ADT.h ADT.cpp data.h
	g++ -Wall -pedantic -g -std=c++11 -c ADT.cpp

clean:
	rm -f data.o main.o ADT.o ADT ADT.exe	
