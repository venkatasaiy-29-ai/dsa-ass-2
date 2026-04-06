#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
        return;
    }
    if(front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

void dequeue() {
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted: %d\n", cq[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", cq[front]);
}

void display() {
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    int i = front;
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
