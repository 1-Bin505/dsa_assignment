//following is the solution of the question number 4

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* start;
Node* end;

void initialize_list()
{
    start = NULL;
    end = NULL;
}

int check_empty() 
{
    return start == NULL;
}

void bot_node(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = end;
    if (check_empty()) 
    {
        start = end = temp;
    } else 
    {
        end->next = temp;
        end = temp;
    }
}

void top_node(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = start;
    temp->prev = NULL;
    if (check_empty()) 
    {
        end = temp;
    } 
    else 
    {
        start->prev = temp;
    }
    start = temp;
}

void display_forward()
{
    if (check_empty()) 
    {
        printf("List is empty\n");
        return;
    }
    Node* current = start;
    printf("The linked list is: ");
    while (current->next != NULL) 
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void display_reverse()
{
    if (check_empty()) 
    {
        printf("List is empty\n");
        return;
    }
    Node* current = end;
    while (current->prev != NULL) 
    {
        printf("%d->", current->data);
        current = current->prev;
    }
    printf("%d\n", current->data);
}

void add_after_value(int target_value, int new_value)
{
    Node* current = start;
    while (current != NULL && current->data != target_value) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        printf("Node with data %d not found.\n", target_value);
        return;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = new_value;
    temp->next = current->next;
    temp->prev = current;
    if (current->next != NULL) 
    {
        current->next->prev = temp;
    } 
    else 
    {
        end = temp; 
    }
    current->next = temp;
    printf("Inserted node with data %d after node with data %d\n", new_value, target_value);
}

int remove_node(int target_value)
{
    Node* current = start;
    while (current != NULL && current->data != target_value) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        printf("Node with data %d not found.\n", target_value);
        return -1;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } 
    else 
    {
        start = current->next; 
    }
    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    } 
    else 
    {
        end = current->prev; 
    }

    int removed_value = current->data;
    free(current);
    return removed_value;
}

int main()
{
    initialize_list();
    bot_node(15);
    bot_node(25);
    bot_node(35);
    top_node(8);
    display_forward();
    printf("Reverse Traversal of the linked list is: ");
    display_reverse();
    add_after_value(25, 30);
    display_forward();
    int removed = remove_node(15);
    printf("Deleted node with data: %d\n", removed);
    display_forward();
    printf("\n");
    return 0;
}