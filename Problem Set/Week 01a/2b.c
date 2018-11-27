#include"stdio.h"
#include"stdlib.h"

#define M 3
#define N 4
#define P 4

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]){
	int value = 0;
	
	for (int i = 0; i < M; i ++){
		for (int j = 0; j < P; j++){
			value = 0;
			for (int k = 0; k < N; k ++){
				value += a[i][k] * b[k][j];
			}
			c[i][j] = value;
			printf("%f ", c[i][j]);
		}
		printf("\n");
	}
}

int main(){
	float a[M][N] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	float b[N][P] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    float c[M][P]; 
	
	matrixProduct(a, b, c);
}