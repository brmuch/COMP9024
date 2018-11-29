#include"stdio.h"
#include"stdlib.h"

int maximum(int a, int b, int c){
    int max = a > b? a:b;
    return max > c? max:c;
}

int main(int argc, char const *argv[])
{
    printf("%d", maximum(55, 2, 3));
    return 0;
}
