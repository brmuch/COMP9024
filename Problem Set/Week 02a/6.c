#include "stdio.h"
#include "stdlib.h"
#include "6.h"

int main(int argc, char const *argv[])
{
    NodeT * all = NULL;
    int value;

    printf("Enter an integer: ");
    while (scanf("%d", &value) != 0){
        NodeT * new = makeNode(value);
        all = joinLL(all, new);
        printf("Enter an integer: ");
    }

    if (all == NULL){
        printf("First half is");
        printf("\nSecond half is");
    }
    else{
        // half and second are two pointer, point to all
        NodeT * half = malloc(sizeof(NodeT));
        NodeT * second = malloc(sizeof(NodeT));
        half -> next = all;
        second -> next = all;

        // divide all into two linked list, half is first one, second is last one
        // second move two steps when half move one step each time
        while (second -> next != NULL){
            half = half -> next;
            second = second -> next;
            if (second -> next != NULL)
                second = second -> next;
            else
                break;
        }
        second = half -> next;

        half -> next = NULL;
        printf("First half is ");
        showLL(all);
        printf("\nSecond half is ");
        showLL(second);
    }
    return 0;
}
