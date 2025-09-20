#include <stdio.h>
int deque[50], front = -1, rear = -1, MAX =5;

void display() {
    if (front == -1) 
        printf("Queue is Empty!\n");
     
    else {
        printf("Queue contents: ");
        int i = front;
        while (1) {
            printf("%d", deque[i]);
            if (i == rear) break;
            printf(" ");
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

void insertRear(int x) {
    if ((rear + 1) % MAX == front) 
        printf("Deque Overflow! Cannot insert more elements.\n");
    
    else {
        if (front == -1) {  
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % MAX;
        }
        deque[rear] = x;
        printf("Inserted %d at rear.\n", x);
    }
}

void insertFront(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Deque Overflow! Cannot insert more elements.\n");
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else {
            front = (front - 1 + MAX) % MAX;
        }
        deque[front] = x;
        printf("Inserted %d at front.\n", x);
    }
}

void deleteFront() {
    if (front == -1) 
        printf("Queue Underflow! Cannot delete.\n");
    
    else {
        printf("Deleted %d from front.\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        printf("Deleted %d from rear.\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + MAX) % MAX;
        }
    }
}

int main() {
    int op, ch, elem;
    scanf("%d", &op);
    for (int i = 0; i < op; i++) {
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                scanf("%d", &elem);
                insertRear(elem);
                display();
                break;
            case 2: 
                scanf("%d", &elem);
                insertFront(elem);
                display();
                break;
            case 3: 
                display();
                break;
            case 4: 
                deleteFront();
                display();
                break;
            case 5: 
                deleteRear();
                display();
                break;
        }
    }
    return 0;
}
