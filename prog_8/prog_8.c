//following is the solution of question 8.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

long long checks = 0;
long long moves = 0;

void exchange(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
    moves++;
}

void bubble_sort(int data[], int size) 
{
    checks = moves = 0;
    for(int i=0;i<size-1;i++) 
    {
        for(int j=0;j<size-i-1;j++) 
        {
            checks++;
            if(data[j] > data[j+1]) 
            {
                exchange(&data[j], &data[j+1]);
            }
        }
    }
}

void selection_sort(int data[], int size) 
{
    checks = moves = 0;
    for(int i=0;i<size-1;i++) 
    {
        int smallest = i;
        for(int j=i+1;j<size;j++) 
        {
            checks++;
            if(data[j] < data[smallest]) 
            {
                smallest = j;
            }
        }
        if(smallest != i) exchange(&data[i], &data[smallest]);
    }
}

void insertion_sort(int data[], int size) 
{
    checks = moves = 0;
    for(int i=1;i<size;i++) 
    {
        int value = data[i];
        int j = i-1;
        while(j>=0 && data[j] > value) 
        {
            checks++;
            data[j+1] = data[j];
            moves++;
            j--;
        }
        if(j>=0) checks++; 
        data[j+1] = value;
    }
}

void combine(int data[], int left, int middle, int right) 
{
    int size1 = middle-left+1;
    int size2 = right-middle;
    int left_arr[size1], right_arr[size2];
    for(int i=0;i<size1;i++) left_arr[i] = data[left+i];
    for(int i=0;i<size2;i++) right_arr[i] = data[middle+1+i];
    int i=0,j=0,k=left;
    while(i<size1 && j<size2) 
    {
        checks++;
        if(left_arr[i] <= right_arr[j]) 
        {
            data[k++] = left_arr[i++];
        } else {
            data[k++] = right_arr[j++];
        }
        moves++;
    }
    while(i<size1) data[k++] = left_arr[i++], moves++;
    while(j<size2) data[k++] = right_arr[j++], moves++;
}

void merge_sort(int data[], int left, int right) 
{
    if(left<right) {
        int middle = left+(right-left)/2;
        merge_sort(data,left,middle);
        merge_sort(data,middle+1,right);
        combine(data,left,middle,right);
    }
}

void display(int data[], int size) 
{
    for(int i=0;i<size;i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() 
{
    int total;
    printf("Enter number of integers: ");
    scanf("%d",&total);
    if(total<=0 || total>MAX) 
    {
        printf("Invalid input! N should be 1-%d\n",MAX);
        return 1;
    }
    int data[total];
    srand(time(0));
    for(int i=0;i<total;i++) data[i] = rand()%1000 + 1;
    printf("\nRandom numbers:\n");
    display(data,total);
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    int option;
    scanf("%d",&option);
    int copy[total];
    for(int i=0;i<total;i++) copy[i] = data[i];
    switch(option) {
        case 1: bubble_sort(copy,total); printf("\nBubble Sort applied.\n"); break;
        case 2: selection_sort(copy,total); printf("\nSelection Sort applied.\n"); break;
        case 3: insertion_sort(copy,total); printf("\nInsertion Sort applied.\n"); break;
        case 4: checks=moves=0; merge_sort(copy,0,total-1); printf("\nMerge Sort applied.\n"); break;
        default: printf("Invalid choice!\n"); return 1;
    }
    printf("\nSorted numbers:\n");
    display(copy,total);
    printf("\nTotal comparisons: %lld\n",checks);
    printf("Total swaps/assignments: %lld\n",moves);
    return 0;
}