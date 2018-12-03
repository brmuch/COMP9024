//Dynamic arrays
/*Write a C-program that uses a dynamic array of 
unsigned long long int numbers (8 bytes, only positive numbers) to compute 
the n'th Fibonacci number, where n is given as command line argument. 
For example, ./fib 60 should result in 1548008755920.
*/

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
    int serial, i;
    if (argc != 2) {
      fprintf(stderr, "Stderr: %s\n", argv[0]);
      return 1;
    }
    serial = atoi(argv[1]);
    
    unsigned long long int * Fib = malloc(serial * sizeof(unsigned long long int));

    Fib[0] = 1;
    Fib[1] = 1;

    for (i = 2; i < serial; i++){
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    printf("%lld\n", Fib[serial - 1]);
    free(Fib);
    return 0;
}
