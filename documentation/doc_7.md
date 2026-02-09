# Documentation for prog_7.c

## Data Structures Used

### 1. Adjacency Matrix (graph[][])
- 2D array to store edge weights
- `graph[i][j]` = weight of edge from vertex i to vertex j
- `graph[i][j]` = 0 means no direct edge

### 2. Distance Array (dist[])
- Stores shortest distance from source to each vertex
- Initially all distances are infinity (INF)
- Source distance is 0

### 3. Visited Array (visited[])
- Tracks which vertices have been processed
- `true` = already processed
- `false` = not yet processed

### 4. Parent Array (parent[])
- Stores the path information
- `parent[i]` tells which vertex comes before i in the shortest path

## Functions Implemented

### 1. minDistance()
- Finds the vertex with minimum distance that hasn't been visited yet
- Used to select the next vertex to process

### 2. printPath()
- Recursively prints the path from source to destination
- Shows the actual route taken

### 3. printSolution()
- Displays the results in a formatted table
- Shows destination, distance, and path for each vertex

### 4. dijkstra()
- **Main algorithm function**
- Steps:
  1. Initialize all distances to infinity except source (0)
  2. Repeat for all vertices:
     - Pick vertex with minimum distance
     - Mark it as visited
     - Update distances of its neighbors
  3. Print the results

### 5. displayGraph()
- Shows the weighted adjacency matrix
- Helps visualize the graph structure

## How the Algorithm Works

1. **Start**: Set distance to source = 0, all others = infinity
2. **Pick**: Choose unvisited vertex with smallest distance
3. **Update**: For each neighbor, check if going through current vertex gives a shorter path
4. **Mark**: Mark current vertex as visited
5. **Repeat**: Steps 2-4 until all vertices are visited

## Main() function Organization

1. **Input Phase**:
   - Get number of vertices
   - Get number of edges
   - Input each edge with its weight

2. **Display Graph**: Show the adjacency matrix

3. **Menu**:
   - Option 1: Find shortest path from a source
   - Option 2: Display graph
   - Option 3: Exit

## Sample Input/Output

### Input
```
Enter the number of vertices: 5
Enter the number of edges: 7
Enter the edges (format: start end weight):
Edge 1: 0 1 10
Edge 2: 0 2 5
Edge 3: 1 2 2
Edge 4: 1 3 1
Edge 5: 2 1 3
Edge 6: 2 3 9
Edge 7: 3 4 2
Enter source vertex: 0
```

### Output
```
=== Shortest Path Results ===
Source Vertex: 0

Destination	Distance	Path
-----------------------------------------------
1		8		0 2 1 
2		5		0 2 
3		9		0 2 1 3 
4		11		0 2 1 3 4 
```
