// Stack ADO implementation ... COMP9024
#include "Stack.h"
#include <assert.h>

#define MAXITEMS 10

static struct {
   int item[MAXITEMS];
   int  top;
} stackObject;  // defines the Data Object

void StackInit() {         // set up empty stack
   stackObject.top = -1;
}

int StackIsEmpty() {       // check whether stack is empty
   return (stackObject.top < 0);
}

void StackPush(int ch) {  // insert integer on top of stack
   assert(stackObject.top < MAXITEMS-1);
   stackObject.top++;
   int i = stackObject.top;
   stackObject.item[i] = ch;
}

int StackPop() {         // remove integer from top of stack
   assert(stackObject.top > -1);
   int i = stackObject.top;
   int ch = stackObject.item[i];
   stackObject.top--;
   return ch;
}