# Build file for OOP Project

.PHONY: all
all: full

full: main.o point.o character.o
	g++ main.o point.o character.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

point.o: point.cpp point.h
	g++ -std=c++11 -c point.cpp

point.h: point.hpp
	g++ -std=c++11 -c point.hpp

character.o: character.cpp character.h
	g++ -std=c++11 -c character.cpp

character.h: character.hpp
	g++ -std=c++11 -c character.hpp

.PHONY: run
run: runmain

runmain:
	./main

.PHONY: clean
clean :
	@rm -f *.o *.h *.gch main
