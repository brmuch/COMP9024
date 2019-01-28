// DFS traverling all graph
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h"
#define SIZE 100 

void components(Graph g){
    int compo[SIZE];
    for (int i = 0; i < g->nV; i ++) {
        for (int j = i + 1; j < g->nV; j++) {
            if (g->edges[i][j] == 1){
                recur_rm(g, i);
            }
        }
    }
}

// recursice remove connected vertices in the graph
int *recur_rm(Graph g, int v){
    for (int i = v + 1; i < g->nV; i ++) {

    }
}

// determine whether all line doesn't connect to another vetices

int main(int argc, char **argv){
    int num;                     // Number of Vertices
    char buff[SIZE];             // Input BUFF

    printf("Enter the number of vertices: ");
    scanf("%d", &num);
    Graph g = newGraph(num);

    printf("Enter an edge (from): ");
    scanf("%s", buff);
    while (strcmp(buff, "done") != 0){
        Edge e;
        e.v = atoi(buff);                     // v

        printf("Enter an edge (to): ");
        scanf("%s", buff);
        e.w = atoi(buff);                     // w
        insertEdge(g, e);                     // insert Edge to Graph

        printf("Enter an edge (from): ");
        scanf("%s", buff);
    }
    printf("Finished.");
    
    components(g);
    return 0;
}