// This is the test file for Q2
#include "stdio.h"
#include "stdlib.h"
#include "Graph.h"

int main(int argc, char **argv){

    // test samples
    // initial graph
    Graph g = newGraph(5);
    Edge e;

    e.v = 0;
    e.w = 1;
    insertEdge(g, e);    //  0 - 1

    e.v = 1;
    e.w = 2;
    insertEdge(g, e);   //  1 - 2

    e.v = 1;
    e.w = 3;
    insertEdge(g, e);   //  1 - 3

    e.v = 0;
    e.w = 4;
    insertEdge(g, e);   //  0 - 4

    e.v = 2;
    e.w = 4;
    insertEdge(g, e);   //  2 - 4
    showGraph(g);

    printf("Graph has Cycle: %d", dfsCycleCheck(g, 0));
    //printf("")
    return 0;
}