#include "stdio.h"
#include "stdlib.h"
#include "1.c"

int main(int argc, char const *argv[])
{
    int k;
    int number = atoi(argv[1]);
    printf("Plz input the base k:");
    scanf("%d", &k);
    StackInit();

    while (number != 0){
        StackPush(number % k);
        number /= k;
    }

    printf("Result:");
    while (!StackIsEmpty()){
        printf("%d", StackPop());
    }
    return 0;
}
