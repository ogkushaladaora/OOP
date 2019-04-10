# Build file for OOP Project

.PHONY: all
all: bulldmain

bulldmain:
	g++ -std=c++11 -c main.cpp
	g++ main.o -o main.exe -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run
run: runmain

runmain:
	./main.exe

.PHONY: clean
clean :
	@rm -f main.exe main.o