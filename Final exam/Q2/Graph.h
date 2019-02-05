// Graph ADT interface ... COMP9024 17s2
#include <stdbool.h>

typedef struct GraphRep *Graph;

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
   Vertex v;
   Vertex w;
} Edge;

Graph newGraph(int);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);

// support function for Q2 in 9024 exam sample
bool hasPath(Graph g,int src,int dest);
bool findPath(Graph g,int src,int dest);
//bool findPathBFS(Graph g,int src,int dest);
bool dfsCycleCheck(Graph g,int v);
//int components(Graph g);
int countReachableNodes(Graph g, int v);
