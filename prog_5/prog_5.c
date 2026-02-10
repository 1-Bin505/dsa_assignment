//follwing is the solution of question no.5

#include <stdio.h>
#define SIZE 70

int graph[SIZE][SIZE];
int checked[SIZE];
int total = 6;

void BFS(int start)
{
    int line[SIZE], first = 0, last = 0;
    for (int i = 0; i < total; i++)
        checked[i] = 0;
    line[last++] = start;
    checked[start] = 1;
    printf("BFS: ");
    while (first < last)
    {
        int node = line[first++];
        printf("%d ", node);
        for (int i = 0; i < total; i++)
        {
            if (graph[node][i] == 1 && checked[i] == 0)
            {
                line[last++] = i;
                checked[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int node)
{
    checked[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < total; i++)
    {
        if (graph[node][i] == 1 && checked[i] == 0)
            DFS(i);
    }
}

int main()
{
    for (int i = 0; i < total; i++)
        for (int j = 0; j < total; j++)
            graph[i][j] = 0;

    graph[0][1] = graph[1][0] = 1;
    graph[0][3] = graph[3][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;

    BFS(0);

    for (int i = 0; i < total; i++)
        checked[i] = 0;

    printf("DFS: ");
    DFS(0);

    return 0;
}