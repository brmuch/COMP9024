// Binary Search Tree ADT implementation ... COMP9024 17s2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "BSTree.h"

#define RANDOM_ROOT_INSERT (random() % 10 < 4)   // 40% chance

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree)  ((tree)->right)

typedef struct Node {
   int  data;
   Tree left, right;
} Node;

// make a new node containing data
Tree newNode(Item it) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   data(new) = it;
   left(new) = right(new) = NULL;
   return new;
}

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree horizontally
// code by Jin Qu
void showTreeR(Tree t, int index, int **record, int *largest) {
  // record largest element along the way
  if (t != NULL) {
    record[index] = &data(t);
    if (data(t) > *largest)
      *largest = data(t);
    showTreeR(left(t), 2 * index + 1, record, largest);
    showTreeR(right(t), 2 * index + 2, record, largest);
  }
}

void showTree(Tree t) {
  int i, h = TreeHeight(t), largest = 0;

  //use an array of pointers to distinguish NULL node and node with value 0
  int **record = calloc(pow(2, h + 1) - 1, sizeof(int*));
  assert(record != NULL);
  showTreeR(t, 0, record, &largest);
  int size, lv = 0;
  if (largest)
    size = floor(log10(largest)) + 1;
  else
    size = 1;
  for (i = 0; i < pow(2, h + 1) - 1; i++) {
    int space = size * ((int)(pow(2, h - lv + 1) - 1) / 2);
    printf("%*s", space, "");

    // centralize nodes
    if (record[i]) {
      printf("%*d", size, *record[i]);
    } else {
      printf("%*s", size, "");
    }
    printf("%*s", space + size, "");
    if (i == pow(2, lv + 1) - 2) {
      printf("\n\n");
      lv++;
    }
  }
  free(record);
}

// compute height of Tree
int TreeHeight(Tree t) {
   if (t == NULL) {
      return 0;
   } else {
      int lheight = 1 + TreeHeight(left(t));
      int rheight = 1 + TreeHeight(right(t));
      if (lheight > rheight)
	 return lheight;
      else
	 return rheight;
   }
}

// count #nodes in Tree
int TreeNumNodes(Tree t) {
   if (t == NULL)
      return 0;
   else
      return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
}

// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
   if (t == NULL)
      return false;
   else if (it < data(t))
      return TreeSearch(left(t), it);
   else if (it > data(t))
      return TreeSearch(right(t), it);
   else                                 // it == data(t)
      return true;
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, Item it) {
   if (t == NULL)
      t = newNode(it);
   else if (it < data(t))
      left(t) = TreeInsert(left(t), it);
   else if (it > data(t))
      right(t) = TreeInsert(right(t), it);
   return t;
}

Tree joinTrees(Tree t1, Tree t2) {
   if (t1 == NULL)
      return t1;
   else if (t2 == NULL)
      return t2;
   else {
      Tree curr = t2;
      Tree parent = NULL;
      while (left(curr) != NULL) {    // find min element in t2
	 parent = curr;
	 curr = left(curr);
      }
      if (parent != NULL) {
	 left(parent) = right(curr);  // unlink min element from parent
	 right(curr) = t2;
      }
      left(curr) = t1;
      return curr;                    // min element is new root
   }
}

// delete an item from a Tree
Tree TreeDelete(Tree t, Item it) {
   if (t != NULL) {
      if (it < data(t))
	 left(t) = TreeDelete(left(t), it);
      else if (it > data(t))
	 right(t) = TreeDelete(right(t), it);
      else {
	 Tree new;
	 if (left(t) == NULL && right(t) == NULL) 
	    new = NULL;
	 else if (left(t) == NULL)    // if only right subtree, make it the new root
	    new = right(t);
	 else if (right(t) == NULL)   // if only left subtree, make it the new root
	    new = left(t);
	 else                         // left(t) != NULL and right(t) != NULL
	    new = joinTrees(left(t), right(t));
	 free(t);
	 t = new;
      }
   }
   return t;
}

Tree rotateRight(Tree n1) {
   if (n1 == NULL || left(n1) == NULL)
      return n1;
   Tree n2 = left(n1);
   left(n1) = right(n2);
   right(n2) = n1;
   return n2;
}

void deleteAVL(Tree t, Item it){
    
}

Tree rotateLeft(Tree n2) {
   if (n2 == NULL || right(n2) == NULL)
      return n2;
   Tree n1 = right(n2);
   right(n2) = left(n1);
   left(n1) = n2;
   return n1;
}

Tree insertAtRoot(Tree t, Item it) { 
   if (t == NULL) {
      t = newNode(it);
   } else if (it < data(t)) {
      left(t) = insertAtRoot(left(t), it);
      t = rotateRight(t);
   } else if (it > data(t)) {
      right(t) = insertAtRoot(right(t), it);
      t = rotateLeft(t);
   }
   return t;
}

Tree insertRandom(Tree t, Item it) { 
   if (t == NULL)
      t = newNode(it);
   if (RANDOM_ROOT_INSERT)
      return insertAtRoot(t, it);
   else
      return TreeInsert(t, it);
}

Tree insertAVL(Tree t, Item it) {
   if (t == NULL)
      return newNode(it);
   if (it == data(t))
      return t;

   if (it < data(t))
      left(t) = insertAVL(left(t), it);
   else
      right(t) = insertAVL(right(t), it);

   int hL = TreeHeight(left(t));
   int hR = TreeHeight(right(t));
   if ((hL - hR) > 1) {
      if (it > data(left(t)))
         left(t) = rotateLeft(left(t));
      t = rotateRight(t);
   } else if ((hR - hL) > 1) {
      if (it  < data(right(t)))
	 right(t) = rotateRight(right(t));
      t = rotateLeft(t);
   }

   return t;
}

Tree partition(Tree t, int i) {
   if (t != NULL) {
      assert(0 <= i && i < TreeNumNodes(t));
      int m = TreeNumNodes(left(t));
      if (i < m) {
	 left(t) = partition(left(t), i);
	 t = rotateRight(t);
      } else if (i > m) {
	 right(t) = partition(right(t), i-m-1);
	 t = rotateLeft(t);
      }
   }
   return t;
}

Tree rebalance(Tree t) {
   int n = TreeNumNodes(t);
   if (n >= 3) {
      t = partition(t, n/2);           // put node with median key at root
      left(t) = rebalance(left(t));    // then rebalance each subtree
      right(t) = rebalance(right(t));
   }
   return t;
}