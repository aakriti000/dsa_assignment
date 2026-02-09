#include <stdio.h>
#include <stdlib.h>

#define MAX 20  

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Stack {
    int items[MAX];
    int top;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isQueueEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack is full!\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

void createGraph(int adjMatrix[][MAX], int vertices) {
    int i, j;
    
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[][MAX], int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; 
}

void displayGraph(int adjMatrix[][MAX], int vertices) {
    int i, j;
    
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (i = 0; i < vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (j = 0; j < vertices; j++) {
            printf("%2d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void BFS(int adjMatrix[][MAX], int vertices, int startVertex) {
    struct Queue* q = createQueue();
    int visited[MAX] = {0};  
    int i;
    
    printf("\nBFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while (!isQueueEmpty(q)) 
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        for (i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(q);
}

void DFSRecursive(int adjMatrix[][MAX], int vertices, int visited[], int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    int i;
    for (i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSRecursive(adjMatrix, vertices, visited, i);
        }
    }
}

void DFSIterative(int adjMatrix[][MAX], int vertices, int startVertex) {
    struct Stack* s = createStack();
    int visited[MAX] = {0};
    int i;
    
    printf("\nDFS Traversal (Iterative) starting from vertex %d: ", startVertex);
    
    push(s, startVertex);
    
    while (!isStackEmpty(s)) {
        int currentVertex = pop(s);
        
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }
    
        for (i = vertices - 1; i >= 0; i--) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(s, i);
            }
        }
    }
    printf("\n");
    free(s);
}

void DFS(int adjMatrix[][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    printf("\nDFS Traversal (Recursive) starting from vertex %d: ", startVertex);
    DFSRecursive(adjMatrix, vertices, visited, startVertex);
    printf("\n");
}

int main() {
    int vertices, edges, i;
    int adjMatrix[MAX][MAX];
    int start, end, startVertex;
    int choice;
    
    printf("=== Graph Implementation using Adjacency Matrix ===\n");
    printf("=== BFS and DFS Traversal ===\n\n");
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices > MAX || vertices <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    createGraph(adjMatrix, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("\nEnter the edges (format: start end):\n");
    for (i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &start, &end);
        
        if (start >= vertices || end >= vertices || start < 0 || end < 0) {
            printf("Invalid edge! Vertices must be between 0 and %d\n", vertices - 1);
            i--; 
            continue;
        }
        
        addEdge(adjMatrix, start, end);
    }
    
    displayGraph(adjMatrix, vertices);
    
    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal (Recursive)\n");
        printf("3. DFS Traversal (Iterative)\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter starting vertex for BFS (0 to %d): ", vertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < vertices) {
                    BFS(adjMatrix, vertices, startVertex);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
                
            case 2:
                printf("Enter starting vertex for DFS (0 to %d): ", vertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < vertices) {
                    DFS(adjMatrix, vertices, startVertex);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
                
            case 3:
                printf("Enter starting vertex for DFS (0 to %d): ", vertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < vertices) {
                    DFSIterative(adjMatrix, vertices, startVertex);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
                
            case 4:
                displayGraph(adjMatrix, vertices);
                break;
                
            case 5:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}