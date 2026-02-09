#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20
#define INF INT_MAX

int minDistance(int dist[], bool visited[], int vertices) {
    int min = INF, minIndex;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void printPath(int parent[], int destination) {
    if (parent[destination] == -1) {
        printf("%d ", destination);
        return;
    }
    
    printPath(parent, parent[destination]);
    printf("%d ", destination);
}

void printSolution(int dist[], int vertices, int parent[], int source) {
    printf("\n=== Shortest Path Results ===\n");
    printf("Source Vertex: %d\n\n", source);
    printf("Destination\tDistance\tPath\n");
    printf("-----------------------------------------------\n");
    
    for (int i = 0; i < vertices; i++) {
        if (i != source) {
            printf("%d\t\t", i);
            
            if (dist[i] == INF) {
                printf("INF\t\tNo path exists\n");
            } else {
                printf("%d\t\t", dist[i]);
                printPath(parent, i);
                printf("\n");
            }
        }
    }
}

void dijkstra(int graph[][MAX], int vertices, int source) {
    int dist[MAX];     
    bool visited[MAX]; 
    int parent[MAX];    

    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[source] = 0;
 
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        
        visited[u] = true;
   
        for (int v = 0; v < vertices; v++) 
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printSolution(dist, vertices, parent, source);
}

void displayGraph(int graph[][MAX], int vertices) {
    printf("\nWeighted Adjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < vertices; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 0) {
                printf("   -");
            } else {
                printf("%4d", graph[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int vertices, edges;
    int graph[MAX][MAX] = {0};  
    int start, end, weight;
    int source;
    int choice;
    
    printf("=== Dijkstra's Algorithm for Shortest Path ===\n\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("\nEnter the edges (format: start end weight):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &start, &end, &weight);
        
        if (start >= vertices || end >= vertices || start < 0 || end < 0) {
            printf("Invalid edge! Vertices must be between 0 and %d\n", vertices - 1);
            i--;
            continue;
        }
        
        if (weight <= 0) {
            printf("Weight must be positive!\n");
            i--;
            continue;
        }
        
        graph[start][end] = weight;
    }
    displayGraph(graph, vertices);
    
    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Find shortest path from a source\n");
        printf("2. Display graph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter source vertex (0 to %d): ", vertices - 1);
                scanf("%d", &source);
                
                if (source < 0 || source >= vertices) {
                    printf("Invalid source vertex!\n");
                } else {
                    dijkstra(graph, vertices, source);
                }
                break;
                
            case 2:
                displayGraph(graph, vertices);
                break;
                
            case 3:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}