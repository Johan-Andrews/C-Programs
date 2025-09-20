
#include <stdio.h>
int queue[50], front = -1, max = 5, rear = -1;

void display() {
  if (front==-1) {
      printf("Queue is Empty!\n");
  } 
  else {
      printf("Circular Queue elements: ");
      int i = front;
      while (1) {
          printf("%d  ", queue[i]);
          if (i == rear)
              break;
          i = (i + 1) % max;
      }
      printf("\n");
  }
}
void enqueue(int el) {
  if (front == -1 && rear == -1) {
    queue[0] = el;
    front = 0;
    rear = 0;
    printf("Inserted %d into the queue.", el);
  } 
  else if ((rear+1)%max ==front) 
    printf("queue overflow");

  else if ((rear == max-1 &&  front>0)) 
  { rear = 0;
    queue[rear] =el;
    printf("Inserted %d into Queue.\n", el);
  }   
  else {
    rear++;
    queue[rear] = el;
    printf("Inserted %d into queue.\n", el);
  }
}

void dequeue() {
  if (rear == -1 && front == -1)
    printf("Queue Underflow! ");

  else if (max-1 >front) {
    front++;
    printf("deleted %d from queue\n", queue[front-1]);
  } 

  else if (front==max-1 && rear>=0)   
  {
    front=0;
    printf("deleted %d\n",  queue[max-1]);
  }
  else {
  front=-1;
  rear=-1;
  }
}

int main() {
  printf("\tMenu for Circular Queue\n1. Insert elements into the queue\n2. Delete "
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
  return 0;
}
