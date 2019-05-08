/*
  listIteratorInt.h 
  Interface to List Iterator that stores integer values
  Written by Ashesh Mahidadia
  Date: December 2018

  *** DO NOT modify this file. *** 
*/

#ifndef LISTITERINT_H
#define LISTITERINT_H

#include <stdio.h>

typedef struct IteratorIntRep *IteratorInt;

IteratorInt IteratorIntNew(); 
int add(IteratorInt it, int v);
int hasNext(IteratorInt it);
int hasPrevious(IteratorInt it);
int *next(IteratorInt it);
int *previous(IteratorInt it);
int deleteElm(IteratorInt it);
int set(IteratorInt it, int v);
int *findNext(IteratorInt it, int v);
int *findPrevious(IteratorInt it, int v);
void reset(IteratorInt it);
void freeIt(IteratorInt it);

#endif
