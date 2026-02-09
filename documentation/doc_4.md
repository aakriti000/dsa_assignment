# Documentation for prog_4.c

## Data Structures Used

### Node Structure
```c
struct Node {
    int data;           // Stores the data value
    struct Node* prev;  // Pointer that points to the previous node
    struct Node* next;  // Pointer that points to the next node
};
```

The doubly linked list is implemented using a structure that contains:
- **data**: Integer value stored in the node
- **prev**: Pointer to the previous node in the list
- **next**: Pointer to the next node in the list

This bidirectional linking allows traversal in both forward and backward directions.

## Functions Implemented

### 1. `createNode(int data)`
- **Purpose**: Dynamically allocates memory for a new node and initializes it
- **Parameters**: Integer data value
- **Returns**: Pointer to the newly created node
- **Description**: Creates a new node with the given data and sets both prev and next pointers to NULL

### 2. `insertAtBeginning(struct Node* head, int data)`
- **Purpose**: Inserts a new node at the beginning of the list
- **Parameters**: Head pointer and data value
- **Returns**: New head pointer
- **Description**: Used for building the initial list in the demonstration

### 3. `insertAfter(struct Node* prevNode, int data)`
- **Purpose**: Inserts a new node after a given node
- **Parameters**: Pointer to the previous node and data value
- **Returns**: void
- **Description**: 
  - Validates that the previous node is not NULL
  - Creates a new node
  - Adjusts pointers to insert the new node after the given node
  - Handles edge cases when inserting after the last node

### 4. `deleteNode(struct Node* head, struct Node* delNode)`
- **Purpose**: Deletes a specific node from the list
- **Parameters**: Head pointer and pointer to the node to be deleted
- **Returns**: Updated head pointer (in case head is deleted)
- **Description**:
  - Handles deletion of head node
  - Adjusts prev and next pointers of adjacent nodes
  - Frees the memory of the deleted node
  - Handles edge cases for first and last nodes

### 5. `searchNode(struct Node* head, int key)`
- **Purpose**: Searches for a node with a given value
- **Parameters**: Head pointer and key value to search
- **Returns**: Pointer to the found node or NULL if not found
- **Description**: Traverses the list to find a node with matching data

### 6. `displayForward(struct Node* head)`
- **Purpose**: Displays the list from head to tail
- **Parameters**: Head pointer
- **Returns**: void
- **Description**: Traverses using next pointers and prints all node values

### 7. `displayBackward(struct Node* head)`
- **Purpose**: Displays the list from tail to head
- **Parameters**: Head pointer
- **Returns**: void
- **Description**: First reaches the tail, then traverses backward using prev pointers

### 8. `freeList(struct Node* head)`
- **Purpose**: Frees all allocated memory
- **Parameters**: Head pointer
- **Returns**: void
- **Description**: Prevents memory leaks by freeing all nodes

## Main() function Organization

The main() function is organized into several sections:

1. **Initialization**: Creates an empty list
2. **Initial List Creation**: Builds a list with values 10, 20, 30, 40, 50
3. **Display Initial State**: Shows the list in both forward and backward directions
4. **Interactive Insert Demonstration**: 
   - Prompts user for insertion point and value
   - Performs insert after operation
   - Displays updated list
5. **Interactive Delete Demonstration**:
   - Prompts user for value to delete
   - Performs deletion
   - Displays updated list
6. **Menu-Driven Interface**: Provides continuous interaction with options for:
   - Insert after a node
   - Delete a node
   - Display list
   - Exit program
7. **Memory Cleanup**: Frees all allocated memory before exit

## Sample Output
```
Creating initial list with values: 10, 20, 30, 40, 50

List (Forward): NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
List (Backward): NULL <-> 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL

Enter the value after which to insert: 30
Enter the value to insert: 35
Node with data 35 inserted after node with data 30

After insertion:
List (Forward): NULL <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <-> NULL

Enter the value to delete: 20
Node with data 20 deleted successfully

After deletion:
List (Forward): NULL <-> 10 <-> 30 <-> 35 <-> 40 <-> 50 <-> NULL
```


