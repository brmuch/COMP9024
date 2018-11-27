#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp, convert;

    for (int number = 10000; number <= 99999; number ++) {
            temp = number;
            convert = 0;
            while (temp > 0) {
                    convert *= 10;
                    convert += temp %10;
                    temp /= 10;
            }
            if (convert == 4 * number) {
                    printf("This 5-digit number is %d.", number);
                    break;
            }
    }
    return 0;
}
