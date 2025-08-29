#include <stdio.h>
int array[50], front = -1, max = 5, rear = -1;

void display() {
  if (front != -1) {
    int c = 0;
    printf("Queue contents:     ");
    while (front <= rear && front != -1) {
      c++;
      printf("%d  ", array[front]);
      front++;
    }
    front -= c;
    printf("\n");

  } else
    printf("Queue Underflow!\n");
}

void enqueue(int el) {
  if (front == -1 && rear == -1) {
    array[0] = el;
    front = 0;
    rear = 0;
    printf("Inserted %d into the queue.", el);
  } else if (rear == max - 1) {
    printf("Queue Overflow!  ");
    printf("Inserted %d into Queue.\n", el);
  } else {
    rear++;
    array[rear] = el;
    printf("Inserted %d into queue.\n", el);
  }
}

void dequeue() {
  if (rear == -1 && front == -1)
    printf("Queue Underflow! ");
  else if (rear == front) {
    front = -1;
    rear = -1;
    printf("deleted %d from queue\n", array[0]);
  } 
  else {
    front++;
    printf("deleted %d\n", array[front - 1]);
  }
}

void main() {
  printf("\tMenu for Queue\n1. Insert elements into the queue\n2. Delete "
         "elements from the queue\n3. Display the contents of the queue.\n");
  int ch, op, elem;
  scanf("%d", &op);
  for (int i = 0; i < op; i++) {
    scanf("%d", &ch);
    switch (ch) {
    case (1): {
      scanf("%d", &elem);
      enqueue(elem);
      display();
      break;
    }

    case (2): {
      dequeue();
      display();
      break;
    }
    case (3): {
      display();
    }
    }
  }
}
