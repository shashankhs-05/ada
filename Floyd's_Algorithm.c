#include <stdio.h>
#define V 4

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {

            if (dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V])
{
printf("shortest distance : \n");
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
printf("%d   ", dist[i][j]);
}
printf("\n");
}
}

int main()
{
    int graph[V][V];
    printf("enter 999 if there is no path to a vertex\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("enter weight from vertex %d to %d : ",i,j);
            scanf("%d",&graph[i][j]);
        }
        printf("\n");
    }

floydWarshall(graph);
return 0;
}
