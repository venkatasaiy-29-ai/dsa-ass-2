#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x) {
    if(top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else 
    {
        stack[++top] = x;
    }
}

// Pop operation
char pop() 
{
    if(top == -1) 
    {
        return '\0';
    } else 
    {
        return stack[top--];
    }
}

// Function to check matching pair
int isMatchingPair(char open, char close) 
{
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}

int main() 
{
    char exp[100];
    int i;
    int balanced = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; i<strlen(exp); i++) 
    {
        char ch = exp[i];

        // If opening bracket, push
        if(ch == '(' || ch == '{' || ch == '[') 
        {
            push(ch);
        }
        // If closing bracket
        else if(ch == ')' || ch == '}' || ch == ']') 
        {
            char popped = pop();

            if(popped == '\0' || !isMatchingPair(popped, ch)) 
            {
                balanced = 0;
                break;
            }
        }
    }

    // If stack not empty, not balanced
    if(top != -1) 
    {
        balanced = 0;
    }

    if(balanced)
    {
        printf("Balanced Expression\n");
    }
    else
    {
        printf("Not Balanced Expression\n");
    }
    return 0;
}
