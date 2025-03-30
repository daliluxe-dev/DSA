#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

//function to add elements to the queue
void enqueue (int value){
    if (rear==MAX-1){
        printf("The queue is full\n");
        return;
    }
    else{
        if (front==-1) front=0;
        queue[++rear]=value;
        printf("%d is enqueued\n", value);
    }
}

//function to remove elements from the queue
void dequeue(){
    if (front==-1 || front > rear) { 
        printf("The queue is empty\n");
        front = rear = -1; 
        return;
    }
    printf("%d is dequeued\n", queue[front]);
    front++;
    if (front > rear) front = rear = -1; 
}

//function to peek at the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

//function to display the array
void display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n"); //check to see if queue is empty/has elements. if not, print the elements
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() { 
    enqueue(10); //calling the enqueue function to add element 
    enqueue(20);
    enqueue(30);
    display();
    peek(); //calling the peek function to look at the front element 
    dequeue(); //calling the dequeue function to remove an element 
    peek(); 
    enqueue(40);
    enqueue(50);
    enqueue(60);  
    display(); //calling the display function to display all the elements in the array

    return 0;
}
