/*
  listIteratorInt.c : list Iterator ADT implementation
  Written by Ran Bai
  Date: December 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

// data structures representing DLList
// one of do_next and do_prev can be 1, when they equal -1, means that dont do prev or next
static int do_next = -1;        // determine whether do next function
static int do_prev = -1;        // determine whether do prev function

typedef struct Node {
    struct Node *next;          // pointer to next node in list
    struct Node *prev;          // pointer previous node in list
    int data;                   // value of this list item (int)
} Node;

typedef struct IteratorIntRep {
    int count;                   // count of items in list
    int origin;                  // 1 is cursor in the first place, 0 is not, -1 is undefinable.
    Node *first;                 // first node in list
    Node *last;                  // last node in list
    Node *cursor;                // cursor node in list, assume cursor is point to the position after the cursor node when origin is 0
} IteratorIntRep;

/*

  Your local functions here, if any.... 


 */
 
// Function: set flag bit to given value
void set_flag(int prev_val, int next_val){
    do_prev = prev_val;
    do_next = next_val;
}


 // Function: Creates a new list iterator that can store integer values.
IteratorInt IteratorIntNew(){
    IteratorIntRep *new;
    new = malloc(sizeof(IteratorIntRep));
    assert(new != NULL);        // memory must be allocated sucessfully
    
    new->count = 0;             // Initial attributes of Iterator
    new->origin = -1;
    new->first = NULL;
    new->last = NULL;
    new->cursor = NULL;
    set_flag(-1, -1);

    return new;
}


// Function: Resets cursor to the start of the list.
void reset(IteratorInt it){
    assert(it->cursor != NULL);
    it->cursor = it->first;
    it->origin = 1;

    set_flag(-1, -1);
}


// Function: Inserts the specified value v into the list iterator it. 
// Returns 1 if successful, 0 otherwise.
int add(IteratorInt it, int v){

    Node * new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return 0;                              // failed malloc memory
    
    new_node->data = v;
    if (it->first == NULL){                  // case1: no node exist in Doubly-linked-list
        new_node->prev = NULL;
        new_node->next = NULL;

        it->first = new_node;                
        it->last = new_node;
        it->cursor = new_node;
        it->origin = 0;
    }
    else if (it->origin == 1){               // case2: add node in the first place
        new_node->prev = NULL;               
        new_node->next = it->first;

        it->first = new_node;                
        it->cursor = new_node;
        it->origin = 0;
    }
    else if (it->cursor == it->last){         // case3: add node in the last place
        new_node->prev = it->cursor;
        new_node->next = NULL;

        it->last = new_node;
        it->cursor->next = new_node;
        it->cursor = new_node;
    }
    else{                                     // case4: add node in the middle place
        new_node->prev = it->cursor;
        new_node->next = it->cursor->next;

        it->cursor->next->prev = new_node;
        it->cursor->next = new_node;
        it->cursor = new_node; 
    }
    
    set_flag(-1, -1);
    it->count ++;
    return 1;         // successful
}


// Function: determine whether has next node
// Returns 1 if the given list iterator has more elements when traversing 
// the list in the forward direction, returns 0 otherwise.
int hasNext(IteratorInt it){
    return (it->first == NULL || (it->cursor == it->last && it->origin == 0))?0:1;  
}


// Function: determine whether has previous node
// Returns 1 if the given list iterator has more elements when traversing 
// the list in the reverse direction, returns 0 otherwise.
int hasPrevious(IteratorInt it){
    return (it->first == NULL || (it->cursor == it->first && it->origin == 1))?0:1; 
}


// Function: Returns the pointer to the next value in the given list iterator and advances the cursor position. 
// The method returns NULL if it has no next value.
int *next(IteratorInt it){
    int *p;

    // return NULl when cursor point to the end or Doubly-lined-list dont have nodes
    if (it->first == NULL || (it->cursor == it->last && it->origin == 0)){
        set_flag(-1, -1);
        return NULL;                  
    }
    else if (it->cursor == it->first && it->origin == 1){
        it->origin = 0;
        p = &(it->cursor->data);
    }
    else{
        it->cursor = it->cursor->next;
        p = &(it->cursor->data);
    }

    set_flag(0, 1);        // sign do next operation already
    return p; 
}


// Function: Returns the pointer to the previous value in the given list iterator and moves the cursor position backwards.
// The method returns NULL if it has no previous value.
int *previous(IteratorInt it){
    int *p;

    if (it->first == NULL || (it->cursor == it->first && it->origin == 1)){
        set_flag(-1, -1);
        return NULL;
    }
    else if (it->cursor == it->first && it->origin == 0){
        p = &(it->cursor->data);
        it->origin =1;
    }
    else{
        p = &(it->cursor->data);
        it->cursor = it->cursor->prev;
    }
    
    set_flag(1, 0);
    return p;  
}


// Function: Deletes from the list iterator the last value that was returned by next or previous or findNext or findPrevious.
// Returns 1 if successful, 0 otherwise (for example, invalid deleteElm call).
int deleteElm(IteratorInt it){
    if (it->first == NULL){                 // no node in the Doubly-lined list
        set_flag(-1, -1);
        return 0;
    }

    if (do_next == 0 && do_prev == 1){       // do prev or findorev before

        if ((it->cursor == it->last && it->count > 1) || (it->count == 1 && it->origin == 0)){    // it cant point to the last node after do prev operation
            set_flag(-1, -1);
            return 0;
        }

        if (it->cursor == it->first && it->origin == 1){   // delete the first node
            if (it->count == 1){              // Doubly-linked list only have one node
                it->first = NULL;
                it->last = NULL;
                free(it->cursor);
                it->cursor = NULL;
                it->origin = -1;
            }
            else{                              // Doubly-linked list have more than one node
                it->first = it->cursor->next;
                Node *temp = it->cursor;
                it->cursor = it->cursor->next;
                it->cursor->prev = NULL;
                free(temp);
            }
        }
        else if (it->cursor->next == it->last){  // delete node in the last place
            Node *temp = it->last;
            it->last = it->cursor;
            it->cursor->next = NULL;
            free(temp);
        }
        else{                                   // delete node in the middle place
            Node *temp = it->cursor->next;
            temp->next->prev = it->cursor;
            it->cursor->next = temp->next;
            free(temp);
        }

    }
    else if (do_next == 1 && do_prev == 0){   // do next or findnext before
        if (it->origin == 1){        // it cant point to the first place after do next operation
            set_flag(-1, -1);
            return 0;      
        }

        if (it->count == 1){             // Doubly-linked list only have one node
            it->first = NULL;
            it->last = NULL;
            free(it->cursor);
            it->cursor = NULL;
            it->origin = -1;
        }
        else if (it->cursor == it->first){    // node in the first place
            Node *temp = it->cursor;
            it->cursor = it->cursor->next;
            it->first = it->cursor;
            it->cursor->prev = NULL;
            it->origin = 1;
            free(temp);
        }
        else if (it->cursor == it->last){     // node in the last place
            Node *temp = it->cursor;
            it->cursor = it->cursor->prev;
            it->last = it->cursor;
            it->cursor->next = NULL;
            free(temp);
        }
        else{                                 // node in the middel place
            Node *temp = it->cursor;
            it->cursor = it->cursor->prev;
            it->cursor->next = temp->next;
            temp->next->prev = it->cursor;
            free(temp);
        }
    }
    else{
        set_flag(-1, -1);
        return 0;
    }
    
    set_flag(-1, -1);     // clear flag
    it->count --;
    return 1;  
}


// Function: Replaces the last element returned by next or previous or findNext or findPrevious with the specified element (v).
// Returns 1 if successful, 0 otherwise (for example, invalid set call).
int set(IteratorInt it, int v){

    if (it->first == NULL){              // Doubly-linked list dont have any node
        set_flag(-1, -1);
        return 0;
    }

    if (do_next == 0 && do_prev == 1){       // do previous operation before
        if (it->cursor == it->first && it->origin == 1){
            it->cursor->data = v; 
        }
        else{
            it->cursor->next->data = v;
        }
    }
    else if (do_next == 1 && do_prev == 0){  // do next operation before
        it->cursor->data = v;
    }
    else{
        set_flag(-1, -1);                   // invalid operation
        return 0;
    }

    set_flag(-1, -1);            // clear flag
    return 1;
}


// Function: Returns pointer to the next value in it that matches the given value v and advances the cursor position past the value returned.
// The method returns NULL if there is no such next value and the cursor is not moved from the current position.
int *findNext(IteratorInt it, int v){

    if (it->first == NULL){              // Doubly-linked list dont have any node
        set_flag(-1, -1);
        return NULL;
    }

    int *p;

    if (it->cursor == it->last && it->origin == 0){    // finish when cursor in the last place
        set_flag(-1, -1);
        return NULL;
    } 
    else{
        Node * current;

        // determine which node is the first one we should start searching
        if (it->origin == 1 && it->cursor == it->first)   
            current = it->cursor;
        else
            current = it->cursor->next;

        // searching...
        while (current != NULL && current->data != v){
            current = current->next;
        }
        
        if (current != NULL){            // find the node has value same to v
            it->origin = 0;
            it->cursor = current;
            p = &(it->cursor->data);
            set_flag(0, 1);
            return p;
        }
        else{                            // can't find corresponding node
            set_flag(-1, -1);
            return NULL;
        }
        
    }
}


// Function: Returns pointer to the previous value in it that matches the given value v and moves the cursor position backwards before the value returned.
// The method returns NULL if there is no such previous value and the cursor is not moved from the current position.
int *findPrevious(IteratorInt it, int v){
    if (it->first == NULL){            // if dont have node in Doubly-linked list
        set_flag(-1, -1);
        return NULL;
    }
    
    int *p;

    if (it->cursor == it->first && it->origin == 1){  // finish when cursor in the first place
        set_flag(-1, -1);
        return NULL;
    }
    else{
        Node *current = it->cursor;

        // searching...
        while (current != NULL && current->data != v){
            current = current->prev;
        }

        if (current == NULL){               // return NUll when can't match
            set_flag(-1, -1);
            return NULL;
        }
        else if (current == it->first){     // find correct node in the head
            it->origin = 1;
            it->cursor = current;
            p = &(current->data);
        }
        else{                               // find correct node in the middle of Doubly-linked list
            it->cursor = current->prev;
            p = &(current->data);
        }
        set_flag(1, 0);              // signed flag bits when succeed
        return p;
    }
}


// Function: Deletes all the nodes in it and frees associated memory.
void freeIt(IteratorInt it){
    Node *p = it->first;

    while (p != NULL){               // free node one by one from first node
        Node *temp = p->next;
        free(p);
        it->count --;
        p = temp;
    }

    set_flag(-1, -1);                     // undefinable associated variable
    it->origin = -1;
    it->first = NULL;
    it->last = NULL;
    it->cursor = NULL;
    free(it);
}

