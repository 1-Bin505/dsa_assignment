//following is the solution of the question number 7

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define SIZE 50            
#define INF INT_MAX        

int find_minimum(int distance[], bool done[], int total)
{
    int minimum = INF;
    int position = -1;
    for (int i = 0; i < total; i++) 
    {
        if (!done[i] && distance[i] < minimum) 
        {
            minimum = distance[i];
            position = i;
        }
    }
    return position;
}

void show_path(int previous[], int node) 
{
    int route[SIZE];
    int count = 0;
    while (node != -1) 
    {
        route[count++] = node;
        node = previous[node];
    }
    for (int i = count - 1; i >= 0; i--) 
    {
        printf("%d", route[i]);
        if (i) printf(" -> ");
    }
}

void shortest_path(int matrix[SIZE][SIZE], int total, int start) 
{
    int distance[SIZE];          
    int previous[SIZE];      
    bool done[SIZE];     
    for (int i = 0; i < total; i++) 
    {
        distance[i] = INF;   
        previous[i] = -1;    
        done[i] = false;
    }
    distance[start] = 0;         
    for (int i = 0; i < total - 1; i++) 
    {
        int current = find_minimum(distance, done, total);
        if (current == -1) break;
        done[current] = true;
        for (int next = 0; next < total; next++) 
        {
            if (!done[next] &&
                matrix[current][next] != INF &&
                distance[current] != INF &&
                distance[current] + matrix[current][next] < distance[next]) 
            {
                distance[next] = distance[current] + matrix[current][next];
                previous[next] = current;
            }
        }
    }
    printf("Source node: %d\n\n", start);
    printf("Node\tDistance\tPath\n");
    for (int i = 0; i < total; i++) 
    {
        if (distance[i] == INF) {
            printf("%d\tINF\t\tNo path\n", i);
        } 
        else 
        {
            printf("%d\t%d\t\t", i, distance[i]);
            show_path(previous, i);
            printf("\n");
        }
    }
}

int main() {
    int total = 6;
    int matrix[SIZE][SIZE] = {
        {0,        7,       3,       INF,     INF,     INF},
        {7,        0,       4,       2,       INF,     INF},
        {3,        4,       0,       INF,     5,       INF},
        {INF,      2,       INF,     0,       6,       3},
        {INF,      INF,     5,       6,       0,       8},
        {INF,      INF,     INF,     3,       8,       0}
    };
    int start = 0;
    shortest_path(matrix, total, start);
    return 0;
}