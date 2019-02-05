// test file for q2 comp9024
#include "stdio.h"
#include "stdlib.h"
#include "Graph.h"

int main(int argc, char **argv) {
	Graph g = newGraph(5);
	Edge e;
	e.v = 0;
	e.w = 1;
	insertEdge(g, e);        // 0 - 1
	e.v = 1;
	e.w = 2;
	insertEdge(g, e);        // 1 - 2
	e.v = 1;
	e.w = 4;
	insertEdge(g, e);        // 1 - 4
	e.v = 0;
	e.w = 3;
	insertEdge(g, e);        // 0 - 3
	e.v = 3;
	e.w = 4;
	insertEdge(g, e);        // 3 - 4
	showGraph(g);            // showGraph
	
	printf("HasPath? %d\n", hasPath(g, 0, 4));
	int src = 0;
	int dest = 4;
	printf("Path from %d to %d? %d\n", src, dest, findPath(g, src, dest));
	//printf("Path from %d to %d? %d\n", src, dest, findPathBFS(g, src, dest));
	printf("HasCycle? %d\n", dfsCycleCheck(g, 0));
	//printf("Components: %d\n", components(g));
	printf("ReachNodes: %d\n", countReachableNodes(g, 0));
}