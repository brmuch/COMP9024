#include"stdio.h"
#include"stdlib.h"
#define SIZE 6

float innerProduct(float a[], float b[], int n) {
    float result = 0;

    for (int i = 0; i < n; i ++) {
        result += a[i] * b[i];
    }

    return result;
}

int main() {
    float a[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    float b[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    printf("The inner product of two vectors is %.2f.", innerProduct(a, b, SIZE));
}
