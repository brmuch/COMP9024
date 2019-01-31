// implement the function int TreeHeight(Tree t)
#include "stdio.h"
#include "stdlib.h"
#include "BSTree.h"

int main(int argc, char **argv){
	Tree t = newTree();
	t = TreeInsert(t, 10);
	t = TreeInsert(t, 5);
	t = TreeInsert(t, 6);
	t = TreeInsert(t, 8);
	t = TreeInsert(t, 1);
	t = TreeInsert(t, 9);
	t = TreeInsert(t, 5);
	printf("The Height of Tree is %d.", TreeHeight(t));
	return 0;
}