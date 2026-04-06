#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) 
{
    if(rear == MAX - 1) 
    {
        printf("Queue Full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}

void dequeue() 
{
    if(front == -1 || front > rear) 
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Printing document %d\n", queue[front++]);
}

void display() 
{
    int i;
    if(front == -1 || front > rear) 
    {
        printf("No pending documents\n");
        return;
    }
    for(i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, doc;

    while(1) 
    {
        printf("\n1.Add 2.Print 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter document ID: ");
                scanf("%d", &doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
