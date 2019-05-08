/*
  client to test listIteratorInt.
  Written by ....
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listIteratorInt.c"
#include "listIteratorInt.h"

void show(IteratorInt it){
    Node * current = it ->first;
        if(it->count == 0){
            printf("^ ");
        }
    while (current != NULL){
        if(current == it->first && it->origin == 1){
            printf("^ ");
        }
        printf("%d ", current->data );
        if(it->origin == 0 && current == it->cursor){
            printf("^ ");
        }
        current = current -> next;
    }
    printf("\n");

    current = it->last;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
  
	  /* The following code, inside the comments, may or may not be correct!
	     
	     It's provided in case you find it difficult to understand 
	     how to create a list iterator, and use it's functions.
	     
	     The code below only tests basic operations, however 
	     make sure that you do test all the required functions properly in
	     your test file. 
*/
	
	  //int val, result;

	  IteratorInt it1 = IteratorIntNew();

	  add(it1, 20);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 20 ^

      add(it1, 12);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 20 12 ^

      add(it1, 33);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //20 12 33 ^

      add(it1, 25);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //20 12 33 25 ^
      
      printf("The previous one is %d.\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //return 25
      //20 12 33 ^ 25

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 33
      // 20 12 ^ 33 25

      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 33
      // 20 12 33 ^ 25

      printf("The result is :%d\n", deleteElm(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // 20 12 ^ 25

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //return 12
      // 20 ^ 12 25

      printf("The result is :%d\n", deleteElm(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // 20 ^ 25

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //return 20
      // ^ 20 25
      
      printf("-------------\n");
      printf("The result is :%d\n", deleteElm(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // ^ 25
      
      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 25
      // 25 ^

      printf("The result is :%d\n", deleteElm(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // ^

      add(it1, 55);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // 55 ^ 

      add(it1, 29);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 1
      // 55 29 ^

      reset(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // ^ 55 29

      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 55
      // 55 ^ 29

      add(it1, 62);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 55 62 ^ 29

      add(it1, 44);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //55 62 44 ^ 29

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 44
      // 55 62 ^ 44 29

      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 44
      // 55 62 44 ^ 29

      deleteElm(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 55 62 ^ 29

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 62
      // 55 ^ 62 29

      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 62
      // 55 62 ^ 29

      deleteElm(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 55 ^ 29

      deleteElm(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 0
      // 55 ^ 29

      printf("The next one is %d\n", *next(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 55 29 ^

      deleteElm(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // 55 ^

      printf("The previous one is %d\n", *previous(it1));
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      // return 55
      // ^ 55

      deleteElm(it1);
      show(it1);
      printf("Number of Node is %d\n", it1->count);
      printf("---------------------------------------------\n");
      //
  return EXIT_SUCCESS;

}
