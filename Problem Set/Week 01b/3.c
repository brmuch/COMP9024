#include "stdio.h"
#include "stdlib.h"
#include "1.c"

int main(int argc, char const *argv[])
{
    StackInit();
    
    for (int i = 1; i < argc; i++){
        StackPush(atoi(argv[i]));
    }

    while (!StackIsEmpty()){
        printf("%d\n", StackPop());
    }
    return 0;
}
