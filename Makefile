#!/bin/bash
# File: Makefile


lab4: Print.o Scanner.o Token.o BinaryTree.o LinkedList.o
	g++ -o lab4 main.cpp Common.h Print.o Scanner.o Token.o BinaryTree.o LinkedList.o

Scanner.o: Scanner.cpp Common.h Scanner.h
	g++ -c Scanner.cpp
	
Token.o: Token.cpp Token.h Common.h
	g++ -c Token.cpp
	
BinaryTree.o: BinaryTree.cpp BinaryTree.h Common.h
	g++ -c BinaryTree.cpp
	
Print.o: Print.cpp Common.h Print.h
	g++ -c Print.cpp
	
LinkedList.o: LinkedList.cpp Common.h LinkedList.h
	g++ -c LinkedList.cpp
clean:
	rm -rf *.o


# !!
# this make is expecting one main in all the .c files
# 4057825488 micheal lackey another adjuster

