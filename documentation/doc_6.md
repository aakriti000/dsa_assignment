# Documentation for prog_6.c

## Data Structure Used

### Array Representation
Heaps are stored in arrays where for any element at index `i`:
- **Parent**: `(i - 1) / 2`
- **Left Child**: `2 * i + 1`
- **Right Child**: `2 * i + 2`

**Example**: Array `[50, 30, 40, 10, 20]`
```
Index:  0   1   2   3   4
Value: 50  30  40  10  20

Tree structure:
       50 (index 0)
      /  \
    30    40 (indices 1, 2)
   /  \
  10  20 (indices 3, 4)
```

## Functions Implemented

### 1. swap()
- **Purpose**: Swaps two elements in the array
- **Parameters**: Two pointers to integers
- **Returns**: void
- **Used in**: Heapify operations

### 2. maxHeapify()
- **Purpose**: Maintains Max Heap property for a subtree
- **Parameters**: Array, size, root index
- **Returns**: void
- **How it works**:
  1. Find the largest among root, left child, and right child
  2. If largest is not root, swap with root
  3. Recursively heapify the affected subtree

### 3. buildMaxHeap()
- **Purpose**: Converts an unsorted array into a Max Heap
- **Parameters**: Array and size
- **Returns**: void
- **How it works**:
  1. Start from the last non-leaf node `(n/2 - 1)`
  2. Call maxHeapify for each node going backwards to root
  3. This ensures heap property from bottom to top

### 4. minHeapify()
- **Purpose**: Maintains Min Heap property for a subtree
- **Parameters**: Array, size, root index
- **Returns**: void
- **How it works**:
  1. Find the smallest among root, left child, and right child
  2. If smallest is not root, swap with root
  3. Recursively heapify the affected subtree

### 5. buildMinHeap()
- **Purpose**: Converts an unsorted array into a Min Heap
- **Parameters**: Array and size
- **Returns**: void
- **How it works**: Same approach as buildMaxHeap but uses minHeapify

### 6. printArray()
- **Purpose**: Displays the array representation of the heap
- **Parameters**: Array and size
- **Returns**: void

### 7. displayHeapTree()
- **Purpose**: Displays the heap in a tree-like visual format
- **Parameters**: Array, size, heap type name
- **Returns**: void
- **Makes it easier**: To visualize the heap structure

### 8. isMaxHeap()
- **Purpose**: Verifies if an array satisfies Max Heap property
- **Parameters**: Array and size
- **Returns**: 1 (true) or 0 (false)
- **Checks**: Every parent is greater than or equal to its children

### 9. isMinHeap()
- **Purpose**: Verifies if an array satisfies Min Heap property
- **Parameters**: Array and size
- **Returns**: 1 (true) or 0 (false)
- **Checks**: Every parent is less than or equal to its children

### 10. displayHeapProperties()
- **Purpose**: Shows parent-child relationships for each node
- **Parameters**: Array, size, heap type name
- **Returns**: void
- **Displays**: Index, value, parent, left child, right child for each element

## Main() function Organization

1. **Input Phase**:
   - Get number of elements
   - Get unsorted array elements
   - Display original array

2. **Menu-Driven Interface**:
   - Option 1: Build and display Max Heap
   - Option 2: Build and display Min Heap
   - Option 3: Display original array
   - Option 4: Exit

3. **For Each Heap Operation**:
   - Copy original array (to preserve it)
   - Build the heap
   - Display array representation
   - Verify heap property
   - Display tree structure
   - Display parent-child properties

## Sample Output
```

Enter the number of elements: 7
Enter 7 elements (unsorted):
Element 1: 45
Element 2: 20
Element 3: 50
Element 4: 10
Element 5: 30
Element 6: 15
Element 7: 40

Original Array: 45 20 50 10 30 15 40 

1. Build and Display Max Heap
2. Build and Display Min Heap
3. Display Original Array
4. Exit
Enter your choice: 1

--- MAX HEAP ---
Max Heap Array: 50 30 45 10 20 15 40 
✓ Max Heap property verified!

Max Heap in Tree Format:
----------------------------------
              50
      30              45
  10      20      15      40
----------------------------------

Max Heap Properties:
Index	Value	Parent	Left Child	Right Child
-----------------------------------------------------
0	50	-	30		45
1	30	50	10		20
2	45	50	15		40
3	10	30	-		-
4	20	30	-		-
5	15	45	-		-
6	40	45	-		-

1. Build and Display Max Heap
2. Build and Display Min Heap
3. Display Original Array
4. Exit
Enter your choice: 2

--- MIN HEAP ---
Min Heap Array: 10 20 15 45 30 50 40 
✓ Min Heap property verified!

Min Heap in Tree Format:
----------------------------------
              10
      20              15
  45      30      50      40
----------------------------------

Min Heap Properties:
Index	Value	Parent	Left Child	Right Child
-----------------------------------------------------
0	10	-	20		15
1	20	10	45		30
2	15	10	50		40
3	45	20	-		-
4	30	20	-		-
5	50	15	-		-
6	40	15	-		-

1. Build and Display Max Heap
2. Build and Display Min Heap
3. Display Original Array
4. Exit
Enter your choice: 3

Original Array: 45 20 50 10 30 15 40 

1. Build and Display Max Heap
2. Build and Display Min Heap
3. Display Original Array
4. Exit
Enter your choice: 4
Exiting program...
```

