#include "stdio.h"
#include "stdlib.h"

/* Makes an array of 10 integers and returns a pointer to it */

int *makeArrayOfInts(void) {
   int * arr;
   arr = malloc(10 * sizeof(int));
   int i;
   for (i=0; i<10; i++) {
      arr[i] = i;
   }
   return arr;
}

int main(int argc, char const *argv[])
{
    int * arrays = makeArrayOfInts();
    for (int i = 0; i < 10; i ++){
        printf("%d\n", arrays[i]);
    } 
    free(arrays);
    return 0;
}
