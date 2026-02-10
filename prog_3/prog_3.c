#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* first;
Node* last;

void initialize()
{
    first = NULL;
    last = NULL;
}

int is_empty() 
{
    return first == NULL;
}

void insert_end(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (is_empty())
    {
        first = last = temp;
    } else 
    {
        last->next = temp;
        last = temp;
    }
}

void insert_beginning(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = first;
    if (is_empty()) 
    {
        last = temp;
    }
    first = temp;
}

void display_forward()
{
    Node* current = first;
    printf("Regular Traversal is: ");
    while (current->next != NULL) 
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void display_backward(Node* current)
{
    if (current == NULL)
        return;
    display_backward(current->next);
    if (current != first)
        printf("%d->", current->data);
    else
        printf("%d", current->data);
}

int main()
{
    initialize();
    insert_end(45);
    insert_beginning(53);
    insert_end(34);
    display_forward();
    printf("Reverse Traversal is: ");
    display_backward(first);
}