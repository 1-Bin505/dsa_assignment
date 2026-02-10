#include <stdio.h>
#include <stdlib.h>

#define MAX 70
char stack[MAX];
int top = -1; 

void push(char data) {
    if(top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = data;
}

char pop() {
    if(top == -1) 
    {
        return '\0'; 
    }
    return stack[top--];
}

void parentheses(char *exp) {
    top = -1; 
    char ch;
    
    for (int i = 0; exp[i] != '\0'; i++) 
    {
        ch = exp[i];
        if(ch == '(' || ch == '{' || ch == '[') 
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']') 
        {
            if (top == -1) 
            {
                printf("Result: Unbalanced (Closing '%c' has no opening)\n", ch);
                return;
            }
            char popped = pop();
            if((ch == ')' && popped != '(') || (ch == '}' && popped != '{') || (ch == ']' && popped != '[')) 
            {
                printf("Result: Unbalanced ('%c' mismatches '%c')\n", ch, popped);
                return;
            }
        }
    }
    
    if(top == -1) {
        printf("Result: Balanced\n");
    } 
    else 
    {
        printf("Result: Unbalanced (Opening '%c' never closed)\n", stack[top]);
    }
}

int main() 
{
    char exp[MAX];
    printf("Enter any expression with parentheses: ");
    scanf("%s", exp);
    parentheses(exp);
    return 0;
//the main function is used to take input as an expression from the user to check for the parenthesis balance.
    
}