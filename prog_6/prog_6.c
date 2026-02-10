//following is the solution of question no.6
#include <stdio.h>
#define MAX 70

void adjust_max(int data[], int size, int index) 
{
    int bigger = index; 
    int l = 2*index + 1; 
    int r = 2*index + 2; 
    if (l < size && data[l] > data[bigger])
        bigger = l;
    if (r < size && data[r] > data[bigger])
        bigger = r;
    if (bigger != index) 
    {
        int swap = data[index];
        data[index] = data[bigger];
        data[bigger] = swap;
        adjust_max(data, size, bigger);
    }
}

void adjust_min(int data[], int size, int index)
 {
    int smaller = index; 
    int l = 2*index + 1; 
    int r = 2*index + 2; 
    if (l < size && data[l] < data[smaller])
        smaller = l;
    if (r < size && data[r] < data[smaller])
        smaller = r;
    if (smaller != index) 
    {
        int swap = data[index];
        data[index] = data[smaller];
        data[smaller] = swap;
        adjust_min(data, size, smaller);
    }
}

void create_max_heap(int data[], int size) 
{
    for (int i = size/2 - 1; i >= 0; i--)
    adjust_max(data, size, i);
}

void create_min_heap(int data[], int size) 
{
    for (int i = size/2 - 1; i >= 0; i--)
    adjust_min(data, size, i);
}

void display(int data[], int size) 
{
    for (int i = 0; i < size; i++)
    printf("%d ", data[i]);
    printf("\n");
}

int main() 
{
    int size;
    int data[MAX];
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    scanf("%d", &data[i]);
    create_max_heap(data, size);
    printf("Max Heap: ");
    display(data, size);
    create_min_heap(data, size);
    printf("Min Heap: ");
    display(data, size);
    return 0;
}