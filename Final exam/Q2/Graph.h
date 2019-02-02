// Graph ADT interface ... COMP9024 17s2
// Create by Ashesh Mahadadia, Modify by Ran Bai
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

// support function for final exam
int hasPath(Graph, int src, int dest);
void findPath(Graph, int src, int dest);
void findPathBFS(Graph, int src, int dest);
int hasCycle(Graph g);
int dfsCycleCheck(Graph g, int v);
void components(Graph);
// count number of nodes reachable from node "v" in a directed graph "g".
int countReachableNodes(Graph, int v);
