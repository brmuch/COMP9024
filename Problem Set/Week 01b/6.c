#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[])
{
    for (int i = strlen(argv[1]); i > 0; i--){
        for (int j = 0; j < i; j++){
            printf("%c", argv[1][j]);
        }
        printf("\n");
    }
    return 0;
}
