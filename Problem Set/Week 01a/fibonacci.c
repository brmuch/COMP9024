#include"stdio.h"
#include"stdlib.h"
#define SIZE 10

void operation(int n){
    if (n == 1) {
        printf("%d\n", n);
    }
    else{
        if (n % 2 == 1){
            printf("%d\n", n);
            operation(3 * n + 1);
        }
        else{
            printf("%d\n", n);
            operation(n / 2);
        }
    }
}

int * Fibonacci(){
    static int F[SIZE];
    if (SIZE < 1){
        return F;
    }
    else if (SIZE == 1){
        F[0] == 1;
        return F;
    }
    else if (SIZE == 2){
        F[0] == 1;
        F[1] == 1;
        return F;
    }
    else{
        F[0] = 1;
        F[1] = 1;
        for (int i = 2; i < SIZE; i++){
            F[i] = F[i-1] + F[i-2];
        }
        return F;
    }
}

int main(int argc, char const *argv[])
{
    int * f = Fibonacci();
    for (int i = 0; i < SIZE; i++){
        printf("Fib[%d] = %d\n", i + 1, f[i]);
        operation(f[i]);
    }
    return 0;
}
