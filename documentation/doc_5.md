# Documentation for prog_5.c

## Data Structures Used

### 1. Adjacency Matrix
```c
int adjMatrix[MAX][MAX];
```
A 2D array where:
- `adjMatrix[i][j] = 1` means there's an edge between vertex i and vertex j
- `adjMatrix[i][j] = 0` means no edge between vertex i and vertex j

**Example**: For a graph with vertices 0, 1, 2, 3 and edges (0-1), (0-2), (1-2), (2-3):
```
   0  1  2  3
0  0  1  1  0
1  1  0  1  0
2  1  1  0  1
3  0  0  1  0
```

### 2. Queue (for BFS)
```c
struct Queue {
    int items[MAX];
    int front;
    int rear;
};
```
Used to store vertices to be visited in BFS. Works on FIFO (First In First Out) principle.

### 3. Stack (for DFS Iterative)
```c
struct Stack {
    int items[MAX];
    int top;
};
```
Used to store vertices to be visited in iterative DFS. Works on LIFO (Last In First Out) principle.

### 4. Visited Array
```c
int visited[MAX] = {0};
```
Keeps track of which vertices have been visited (1 = visited, 0 = not visited).

## Functions Implemented

### Graph Creation Functions

#### 1. createGraph()
- Initializes the adjacency matrix with all zeros
- Sets up an empty graph

#### 2. addEdge()
- Adds an edge between two vertices
- Since it's undirected, it sets both `adjMatrix[start][end]` and `adjMatrix[end][start]` to 1

#### 3. displayGraph()
- Prints the adjacency matrix in a readable format
- Shows all connections in the graph

### BFS Functions

#### 4. createQueue()
- Creates and initializes an empty queue

#### 5. enqueue()
- Adds a vertex to the rear of the queue

#### 6. dequeue()
- Removes and returns a vertex from the front of the queue

#### 7. BFS()
- **Purpose**: Traverses the graph level by level
- **How it works**:
  1. Start from a given vertex
  2. Visit all neighbors of current vertex
  3. Then visit neighbors of those neighbors
  4. Continue until all reachable vertices are visited
- **Uses**: Queue to maintain order of vertices to visit

### DFS Functions

#### 8. createStack()
- Creates and initializes an empty stack

#### 9. push()
- Adds a vertex to the top of the stack

#### 10. pop()
- Removes and returns a vertex from the top of the stack

#### 11. DFSRecursive()
- **Purpose**: Traverses the graph going as deep as possible before backtracking
- **How it works**:
  1. Visit current vertex
  2. Recursively visit an unvisited neighbor
  3. Backtrack when no unvisited neighbors
- **Uses**: Function call stack (recursion)

#### 12. DFS()
- Wrapper function that initializes visited array and calls DFSRecursive()

#### 13. DFSIterative()
- **Purpose**: Same as DFS but uses explicit stack instead of recursion
- **How it works**: Similar to recursive DFS but manages stack manually

## Main() function Organization

1. **Get Graph Details**:
   - Ask user for number of vertices
   - Ask user for number of edges
   - Input all edges

2. **Create Graph**:
   - Initialize adjacency matrix
   - Add all edges to the matrix

3. **Display Graph**:
   - Show the adjacency matrix

4. **Menu-Driven Interface**:
   - Option 1: Perform BFS from a chosen starting vertex
   - Option 2: Perform DFS (Recursive) from a chosen starting vertex
   - Option 3: Perform DFS (Iterative) from a chosen starting vertex
   - Option 4: Display the adjacency matrix again
   - Option 5: Exit

## Sample Output
```

Enter the number of vertices: 5
Enter the number of edges: 6

Enter the edges (format: start end):
Edge 1: 0 1
Edge 2: 0 2
Edge 3: 1 2
Edge 4: 1 3
Edge 5: 2 4
Edge 6: 3 4

Adjacency Matrix:
    0  1  2  3  4 
 0  0  1  1  0  0 
 1  1  0  1  1  0 
 2  1  1  0  0  1 
 3  0  1  0  0  1 
 4  0  0  1  1  0 

=== Menu ===
1. BFS Traversal
2. DFS Traversal (Recursive)
3. DFS Traversal (Iterative)
4. Display Graph
5. Exit
Enter your choice: 1
Enter starting vertex for BFS (0 to 4): 0

BFS Traversal starting from vertex 0: 0 1 2 3 4 

=== Menu ===
1. BFS Traversal
2. DFS Traversal (Recursive)
3. DFS Traversal (Iterative)
4. Display Graph
5. Exit
Enter your choice: 2
Enter starting vertex for DFS (0 to 4): 0

DFS Traversal (Recursive) starting from vertex 0: 0 1 2 4 3 

=== Menu ===
1. BFS Traversal
2. DFS Traversal (Recursive)
3. DFS Traversal (Iterative)
4. Display Graph
5. Exit
Enter your choice: 5
Exiting program...
```

## Example Graph Visualization

For the sample input above, the graph looks like:
```
    0
   / \
  1   2
  |   |
  3---4
```

- **BFS from 0**: Visits 0, then its neighbors (1, 2), then their neighbors (3, 4)
- **DFS from 0**: Visits 0, then goes deep through 1→2→4→3

