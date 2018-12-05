//Dynamic linked lists
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef struct node {
    struct node * next;
    int data;
}NodeT;

NodeT *makeNode(int value){
    NodeT * nd = malloc(sizeof(NodeT));
    assert(nd != NULL);
    nd -> data = value;
    nd -> next = NULL;
    
    return nd;
}

void freeLL(NodeT *list) {
    NodeT *p = list;
    while (p != NULL) {
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

void showLL(NodeT *head){
    NodeT * cursor = head;
    while (cursor != NULL){
        printf("%d",cursor -> data);
        cursor = cursor -> next;
        if (cursor != NULL){
            printf("->");
        }
    }
}

NodeT *joinLL(NodeT *head1, NodeT *head2){
    if (head1 == NULL){
        head1 = head2;
    }
    else{
        NodeT * cursor = head1;
        while (cursor -> next != NULL){
            cursor = cursor -> next;
        }
        cursor -> next = head2;
    }
    return head1;
}

int main(int argc, char const *argv[])
{
   NodeT * all = NULL;
   int value;

   printf("Enter a integer: ");    
   while (scanf("%d", &value) == 1){
      NodeT * new = makeNode(value);
      all = joinLL(all, new);
      printf("Enter a integer: ");
   }

   printf("Finished.");
   if (all == NULL)
      exit(0);
   else{
      printf(" List is: ");
      showLL(all);
   }
      
   return 0;
}
