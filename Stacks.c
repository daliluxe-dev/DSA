#include <stdio.h>
#define MAX 6  // Define the maximum size of the stack

int stack[MAX];  // Declare the stack array
int top = -1;    // Initialize top pointer to -1 (empty stack)

// Function to push an element onto the stack
void push(int x) {
    if (top == MAX - 1) {  // Check if the stack is full
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;  // Increment top and insert the element
        printf("%d is added\n", x);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack underflow (stack empty)\n");
        return -1;
    } else {
        int y = stack[top--];  // Remove top element and decrease top
        printf("%d has been removed\n", y);
        return y;
    }
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {  // Check if the stack is empty
        printf("Nothing to display\n");
    } else {
        printf("%d is at the top\n", stack[top]);  // Display top element
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {  // Check if the stack is empty
        printf("Nothing to display\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {  // Print elements from top to bottom
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(20);  // Push elements onto the stack
    push(20);
    peek();    // Peek at the top element
    push(40);
    push(70);
    push(90);
    push(110);
    push(19);
    display(); // Display all stack elements

    pop(); // Pop elements from the stack
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}
