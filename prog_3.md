# Documentation for prog_3.c

## Data Structures Used

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

- **data**: Stores the integer value
- **next**: Pointer to the next node in the list

This is a singly linked list where each node points to the next node, and the last node points to NULL.

## Functions Implemented

### 1. `Node* createNode(int data)`
**Purpose**: Creates and initializes a new node with given data
**Returns**: Pointer to the newly created node
**Memory**: Allocates memory dynamically using malloc()

### 2. `void insertAtEnd(Node **head, int data)`
**Purpose**: Inserts a new node at the end of the linked list
**Parameters**: 
- Double pointer to head (to modify the head if list is empty)
- Data value to insert
**Algorithm**:
- Create new node
- If list is empty, make new node the head
- Otherwise, traverse to last node and link it

### 3. `void displayList(Node *head)`
**Purpose**: Displays the linked list in forward direction
**Output Format**: `10 -> 20 -> 30 -> 40 -> 50`

### 4. `void reverseTraversal(Node *head)`
**Purpose**: Core function implementing reverse traversal using recursion
**Algorithm**:
- Base case: If node is NULL, return
- Recursive case: First call reverseTraversal on next node
- After recursion returns, print current node's data
**How it works**: Uses the call stack to achieve reverse order. The recursion goes to the end first, then prints while unwinding the stack.

### 5. `void displayReverseTraversal(Node *head)`
**Purpose**: Wrapper function to display reverse traversal with formatting
**Output Format**: `Reverse Traversal: 50 40 30 20 10`

### 6. `int countNodes(Node *head)`
**Purpose**: Counts total number of nodes in the list
**Returns**: Integer count of nodes
**Algorithm**: Simple traversal counting each node

### 7. `void freeList(Node **head)`
**Purpose**: Frees all memory allocated for the linked list
**Importance**: Prevents memory leaks by deallocating all nodes

## main() Method Organization

The main function is organized into three sections:

### 1. Demonstration Section
- Creates a sample linked list with values: 10, 20, 30, 40, 50
- Displays normal forward traversal
- Displays reverse traversal
- Shows the working of reverse traversal algorithm

### 2. Interactive Menu Section
Provides 5 options:
1. Insert element at end - Add new elements to the list
2. Display list (forward) - Show normal traversal
3. Display list (reverse) - Demonstrate reverse traversal
4. Count nodes - Show total nodes in list
5. Exit - Free memory and exit program

### 3. User Interaction Loop
- Continuously accepts user input
- Performs requested operations
- Validates input and provides appropriate feedback

## Sample Output

1. Insert element at end
2. Display list (forward)
3. Display list (reverse)
4. Count nodes
5. Exit
Enter your choice: 1
Enter data to insert: 60
Element 60 inserted successfully!

1. Insert element at end
2. Display list (forward)
3. Display list (reverse)
4. Count nodes
5. Exit
Enter your choice: 3
Reverse Traversal: 60 50 40 30 20 10 

1. Insert element at end
2. Display list (forward)
3. Display list (reverse)
4. Count nodes
5. Exit
Enter your choice: 4
Total nodes in list: 6

1. Insert element at end
2. Display list (forward)
3. Display list (reverse)
4. Count nodes
5. Exit
Enter your choice: 5

Freeing memory and exiting
Thank you for using the program!
```

## How to Compile and Run

```bash
gcc prog_3.c -o prog_3
./prog_3.exe
```

## Algorithm Explanation

### Reverse Traversal Algorithm (Recursive)
1. If current node is NULL, return (base case)
2. Recursively call function on next node
3. Print current node's data

**Why this works**: The recursion first reaches the last node, then prints values while returning back through the call stack, effectively printing in reverse order.

**Call Stack Visualization**:
```
reverseTraversal(10) calls reverseTraversal(20)
  reverseTraversal(20) calls reverseTraversal(30)
    reverseTraversal(30) calls reverseTraversal(40)
      reverseTraversal(40) calls reverseTraversal(50)
        reverseTraversal(50) calls reverseTraversal(NULL)
        reverseTraversal(NULL) returns
        Print 50
      Print 40
    Print 30
  Print 20
Print 10
```

## Time and Space Complexity

- **Time Complexity**: O(n) - visits each node once
- **Space Complexity**: O(n) - recursion stack depth equals number of nodes