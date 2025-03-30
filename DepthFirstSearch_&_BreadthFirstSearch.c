#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100 //this is the maximum size for BFS queue

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node *child; // First child
    struct Node *sibling; // Next sibling
} Node;

//a function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

//Depth-First Search that uses recursion function
void dfs(Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data); // Visit the node
    dfs(root->child);   //recursively visit the child first
    dfs(root->sibling); //then visit the next sibling 
} 

//Breadth-First Search that uses a queue
void bfs(Node* root) {
    if (root == NULL)
        return;

    Node* queue[MAX_QUEUE];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data); // Visit the node
    
        if (current->child)
            queue[rear++] = current->child;  //enqueue the first child
        Node* sibling = current->child; //Then enqueue all siblings of the first child
        while (sibling && sibling->sibling) {
            queue[rear++] = sibling->sibling;
            sibling = sibling->sibling;
        }
    }
}

int main() {
    // Creating a tree structure
    Node* root = createNode(1);
    root->child = createNode(2);
    root->child->sibling = createNode(3);
    root->child->sibling->sibling = createNode(4);
    
    root->child->child = createNode(5);
    root->child->child->sibling = createNode(6);
    
    root->child->sibling->child = createNode(7);
    root->child->sibling->child->sibling = createNode(8);

    printf("DFS Traversal: ");
    dfs(root);
    printf("\n");

    printf("BFS Traversal: ");
    bfs(root);
    printf("\n");

    return 0;
}
