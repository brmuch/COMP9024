# Makefile for listIteratorInt 

CC = gcc
CFLAGS = -Wall -Werror -g

all : testListIterInt

testListIterInt : listIteratorInt.o testListIteratorInt.o 
	$(CC) -o testListIterInt  listIteratorInt.o testListIteratorInt.o

testListIteratorInt.o: testListIteratorInt.c listIteratorInt.h
	$(CC) $(CFLAGS) -c  testListIteratorInt.c

listIteratorInt.o : listIteratorInt.c  listIteratorInt.h
	$(CC) $(CFLAGS) -c  listIteratorInt.c
	
clean :
	rm -f *.o   testListIterInt core

