
#include <stdio.h>

int adj[10][10], n, vis[10];
int stack[10];
int top = -1;

void push(int);
int pop();
void display();

void dfs(int);

int main()
{
    printf("\nEnter the size of adjacency matrix: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
        vis[i] = 0;
    }
    printf("\nTopological Order: ");
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    display();
    return 0;
}

void push(int ele)
{
    if (top < 10)
    {
        stack[++top] = ele;
    }
}

int pop()
{
    return stack[top--];
}

void dfs(int ele)
{
    vis[ele] = 1;
    for (int j = 0; j < n; j++)
    {
        if (adj[ele][j] == 1 && vis[j] == 0)
        {
            dfs(j);
        }
    }
    push(ele);
}

void display()
{
    while (top != -1)
    {
        printf("%d ", pop() + 1);
    }
}
