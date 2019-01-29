// DFS traverling all graph
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Graph.h"
#include "stack.h"
#define SIZE 1000

// Function used for sorting
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

extern bool IsTravel(int *compo, int v, int length);

void components(Graph g){
    int all_traverl[SIZE];                           // initial
    int compo[SIZE];
    int size = 0, all_size = 0, part = 1;
    stack st = newStack();

    for (int i = 0; i < g->nV;) {
        StackPush(st, i);
        // sign all nodes connected to nodes in the stack
        while (!StackIsEmpty(st)){
            int p = StackPop(st);
            compo[size] = p;
            all_traverl[all_size] = p;
            size ++;
            all_size ++;
            
            for (int k = p + 1; k < g->nV; k ++) {
                if (g->edges[p][k] != 0){
                    if (!IsTravel(compo, k, size)){
                        StackPush(st, k);
                    }
                    g->edges[p][k] = 0;
                }
            }
        }
        // print components
        qsort(compo, size, sizeof(int), comp);
        printf("Component %d:\n", part);
        for (int k = 0; k < size; k ++) {
            printf("%d\n", compo[k]);
        }

        size = 0;
        do{
            i ++;
        }while (IsTravel(all_traverl, i, all_size));
        part ++;
    }
    printf("Number of components: %d", part - 1);
}

// determine whether add node already traverling
bool IsTravel(int *compo, int v, int length) {
    for (int i = 0; i < length; i ++) {
        if (compo[i] == v){
            return true;
        }
    }
    return false;
}

// Main Function
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
    printf("Finished.\n");
    
    components(g);
    return 0;
}