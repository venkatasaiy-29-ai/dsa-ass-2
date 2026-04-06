#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x) 
{
    if(top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else 
    {
        stack[++top] = x;
    }
}

// Pop operation
char pop() {
    if(top == -1) 
    {
        printf("Stack Underflow\n");
        return '\0';
    } else 
    {
        return stack[top--];
    }
}

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters into stack
    for(i = 0; i < strlen(str); i++) 
    {
        push(str[i]);
    }

    /*Pop characters to reverse string*/
    printf("Reversed string: ");
    for(i = 0; i < strlen(str); i++) 
    {
        printf("%c", pop());
    }

    return 0;

}
