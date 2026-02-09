#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
    printf("Node with data %d inserted after node with data %d\n", data, prevNode->data);
}

struct Node* deleteNode(struct Node* head, struct Node* delNode) {
    if (head == NULL || delNode == NULL) {
        printf("Cannot delete. List is empty or node doesn't exist!\n");
        return head;
    }
    
    if (head == delNode) {
        head = delNode->next;
    }
    
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    printf("Node with data %d deleted successfully\n", delNode->data);
    free(delNode);
    return head;
}

struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List (Forward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("List (Backward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* targetNode = NULL;
    int choice, data, afterData, deleteData;
    
    printf("=== Doubly Linked List Operations ===\n\n");
    
    printf("Creating initial list with values: 10, 20, 30, 40, 50\n");
    head = insertAtBeginning(head, 50);
    head = insertAtBeginning(head, 40);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    
    printf("\nInitial ");
    displayForward(head);
    displayBackward(head);
    
    printf("\n--- Insert After Operation ---\n");
    printf("Enter the value after which to insert: ");
    scanf("%d", &afterData);
    printf("Enter the value to insert: ");
    scanf("%d", &data);
    
    targetNode = searchNode(head, afterData);
    if (targetNode != NULL) {
        insertAfter(targetNode, data);
        printf("\nAfter insertion:\n");
        displayForward(head);
        displayBackward(head);
    } else {
        printf("Node with value %d not found!\n", afterData);
    }
    
    printf("\n--- Delete Operation ---\n");
    printf("Enter the value to delete: ");
    scanf("%d", &deleteData);
    
    targetNode = searchNode(head, deleteData);
    if (targetNode != NULL) {
        head = deleteNode(head, targetNode);
        printf("\nAfter deletion:\n");
        displayForward(head);
        displayBackward(head);
    } else {
        printf("Node with value %d not found!\n", deleteData);
    }
    
    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Insert after a node\n");
        printf("2. Delete a node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value after which to insert: ");
                scanf("%d", &afterData);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                targetNode = searchNode(head, afterData);
                if (targetNode != NULL) {
                    insertAfter(targetNode, data);
                    displayForward(head);
                } else {
                    printf("Node with value %d not found!\n", afterData);
                }
                break;
                
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &deleteData);
                targetNode = searchNode(head, deleteData);
                if (targetNode != NULL) {
                    head = deleteNode(head, targetNode);
                    displayForward(head);
                } else {
                    printf("Node with value %d not found!\n", deleteData);
                }
                break;
                
            case 3:
                displayForward(head);
                displayBackward(head);
                break;
                
            case 4:
                printf("Freeing memory and exiting...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}