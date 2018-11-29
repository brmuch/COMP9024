#include <stdio.h>
#include "stdlib.h"
#include "1.c"

int main(int argc, char const *argv[])
{
   int num, temp;
   
   StackInit();
   printf("Enter a positive number: ");
   scanf("%d", &num);

   for (int i = 0; i < num; i++){
      printf("Enter a number: ");
      scanf("%d", &temp);
      StackPush(temp);
   }

   for (int i = 0; i < num; i++){
      printf("%d\n", StackPop());
   }
   return 0;
}