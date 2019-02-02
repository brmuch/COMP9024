// Graph ADT
// Adjacency Matrix Representation ... COMP9024 17s2
// Create by Ashesh Mahadadia, Modify by Ran Bai
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

Graph newGraph(int V) {
   assert(V >= 0);
   int i;

   Graph g = malloc(sizeof(GraphRep));
   assert(g != NULL);
   g->nV = V;
   g->nE = 0;

   // allocate memory for each row
   g->edges = malloc(V * sizeof(int *));
   assert(g->edges != NULL);
   // allocate memory for each column and initialise with 0
   for (i = 0; i < V; i++) {
      g->edges[i] = calloc(V, sizeof(int));
      assert(g->edges[i] != NULL);
   }

   return g;
}

// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (!g->edges[e.v][e.w]) {  // edge e not in graph
      g->edges[e.v][e.w] = 1;
      g->edges[e.w][e.v] = 1;
      g->nE++;
   }
}

void removeEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (g->edges[e.v][e.w]) {   // edge e in graph
      g->edges[e.v][e.w] = 0;
      g->edges[e.w][e.v] = 0;
      g->nE--;
   }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
   assert(g != NULL && validV(g,v) && validV(g,w));

   return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
       for (j = i+1; j < g->nV; j++)
	  if (g->edges[i][j])
	      printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
   assert(g != NULL);

   int i;
   for (i = 0; i < g->nV; i++)
      free(g->edges[i]);
   free(g->edges);
   free(g);
}

//Q1:
// determine whether has path from src to dest
int hasPath(Graph g, int src, int dest){
    int * mark = calloc(g->nV, sizeof(int));
    return dfsPathCheck(g, mark, src, dest);
}

// dfs travel support function for hasPath function
int dfsPathCheck(Graph g, int *mark, int src, int dest){
    // mark src already traveled
    mark[src] = 1;
    if (src == dest){
        return 1;
    }
    for (int i = 0; i < g->nV; i ++) {
        if (mark[i] != 1 && g->edges[src][i] == 1 ){
            if (dfsPathCheck(g, mark, i, dest)){
                return 1;
            }
        }
    }
    return 0;
}


//Q2:
// find path from src to destination in given graph
void findPath(Graph g, int src, int dest){
    // initial route array
    int *mark = malloc(g->nV * sizeof(int));
    for (int i = 0; i < g->nV; i ++) {
        if (i == dest)
            mark[i] = dest;
        else
            mark[i] = -1;
    }
    dfsPathTravel(g, mark, src, dest);

    
    if (mark[dest] == dest && dest != src){             // don't find path from src to dest
        printf("No paths from %d to %d\n", src, dest);
    }
    else{                                               // already find path in mark array
        int index = mark[dest];
        while (index != src) {
            printf("%d-", index);
            if (index == src)
                break;
            index = mark[index];
        }
        printf("\n");
    }
}

void dfsPathTravel(Graph g, int * mark, int src, int dest){
    // if mark[i] != -1 means already traveled, else no
    if (src == dest)
        return;
    for (int i = 0; i < g->nV; i ++) {
        if (mark[src] == -1 && g->edges[src][i] == 1){
            mark[i] = src;
            dfsPathTravel(g, mark, i, dest);
        }
    }
        
}

//Q3:
// determine whether given graph have cycle
int hasCycle(Graph g) {
    return dfsCycleCheck(g,0);
} 

// dfs support function for hasCycle
int dfsCycleCheck(Graph g, int v) {

}