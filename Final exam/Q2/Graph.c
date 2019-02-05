// Graph ADT
// Adjacency Matrix Representation ... COMP9024 17s2
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

// Q1
extern bool dfs_hasPath(Graph g, int src, int dest, int *visited);
bool hasPath(Graph g,int src,int dest) {
	int * visited = calloc(g->nV, sizeof(int));
	return dfs_hasPath(g, src, dest, visited);
}

// dfs support function for hasPath
bool dfs_hasPath(Graph g, int src, int dest, int *visited) {
	visited[src] = 1;
	
	for (int i = 0; i < g->nV; i ++) {
		if (g->edges[src][i] == 1 && visited[i] == 0) {
			if (i == dest)
				return true;
			else if (dfs_hasPath(g, i, dest, visited)){
				return true;
			}
		}
	}
	return false;
}

// Q2
extern bool dfs_findPath(Graph g, int src, int dest, int *visited);
bool findPath(Graph g,int src,int dest) {
	int *visited = malloc(g->nV * sizeof(int));
	// initial visited array
	for (int i = 0; i < g->nV; i ++) {
		visited[i] = -1;
	}
	visited[src] = src;
	
	if (dfs_findPath(g, src, dest, visited)) {
		int index = dest;
		while (index != src) {
			printf("%d-", index);
			index = visited[index];
		}
		printf("%d\n", index);
		return true;
	}
	else {
		printf("can not find a path from %d to %d.\n", src, dest);
		return false;
	}
}

// support funciton for findPath
bool dfs_findPath(Graph g, int src, int dest, int *visited) {
	for (int i = 0; i < g->nV; i ++) {
		if (g->edges[src][i] == 1 && visited[i] == -1) {
			visited[i] = src;
			if (i == dest)
				return true;
			else if (dfs_findPath(g, i, dest, visited))
				return true;
		}
	}
	return false;
}

//Q3 warning: exit the node from
extern bool dfs_CycleCheck(Graph g, int v, int *visited, int from);
bool dfsCycleCheck(Graph g,int v) {
	int *visited = calloc(g->nV, sizeof(int));
	return dfs_CycleCheck(g, v, visited, -1);
}

bool dfs_CycleCheck(Graph g, int v, int *visited, int from) {
	visited[v] = 1;
	
	for (int i = 0; i < g->nV; i ++) {
		if (g->edges[v][i] == 1 && i != from){
			if (visited[i] == 1)
				return true;
			else if (dfs_CycleCheck(g, i, visited, v)){
				return true;
			}
		}
	}
	return false;
}

//Q4:
extern void dfs_countReachableNodes(Graph g, int v, int *visited);
int countReachableNodes(Graph g, int v) {
	int *visited = calloc(g->nV, sizeof(int));
	int count = 0;
	dfs_countReachableNodes(g, v, visited);
	for (int i = 0; i < g->nV; i ++) {
		for (int j = i + 1; j < g->nV; j ++)
		if (g->edges[i][j])
			count ++;
	}
	free(visited);
	return count;
}

void dfs_countReachableNodes(Graph g, int v, int *visited) {
	visited[v] = 1;
	
	for (int i = 0; i < g->nV; i ++) {
		if (g->edges[v][i] == 1 && visited[i] == 0) {
			dfs_countReachableNodes(g, i, visited);
		}
	}
}