// Auto Test For final exam Q1
#include "stdio.h"
#include "stdlib.h"
#include "BSTree.h"

int main(int argc, char ** argv){
    Tree t = newTree();                  // build a test tree

    t = TreeInsert(t, 10);
    t = TreeInsert(t, 5);
    t = TreeInsert(t, 4);
    t = TreeInsert(t, 7);

    t = TreeInsert(t, 15);
    t = TreeInsert(t, 1);
    // t = TreeInsert(t, 12);
    //t = TreeInsert(t, 21);
    showTree(t);

    printf("Tree height is %d\n", TreeHeight(t));
    printf("Tree Balanced: %d\n", isBalanced(t));
    printf("Leaf number of Tree: %d\n", countLeaf(t));
    printf("Odds number Nodes: %d\n", countOdds(t));
}