#include <stdio.h>

#define MAX_VERTICES 10

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start, int visited[])
{
    visited[start] = 1;

    for (int i = 0; i < num_vertices; i++)
    {
        if (graph[start][i] && !visited[i])
        {
            dfs(graph, num_vertices, i, visited);
        }
    }
}

int is_connected(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices)
{
    int visited[MAX_VERTICES] = {0};


    dfs(graph, num_vertices, 0, visited);

    // Check if all vertices were visited
    for (int i = 0; i < num_vertices; i++)
    {
        if (!visited[i])
        {
            return 0; // Graph is not connected
        }
    }

    return 1;
}

int main()
{
    int num_vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }


    if (is_connected(graph, num_vertices))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}
