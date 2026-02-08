#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraversal(Node *head) {
    if (head == NULL) {
        return;
    }
    
    
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

void displayReverseTraversal(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Reverse Traversal: ");
    reverseTraversal(head);
    printf("\n");
}

int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void freeList(Node **head) {
    Node *current = *head;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    Node *head = NULL;
    int choice, data;
    
    printf("=== Reverse Traversal of Linked List ===\n\n");
    
    
    printf("Creating a sample linked list with values: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
   
    displayList(head);
    
   
    displayReverseTraversal(head);
    
    printf("\n--- Interactive Menu ---\n");
    
    while (1) {
        printf("\n1. Insert element at end\n");
        printf("2. Display list (forward)\n");
        printf("3. Display list (reverse)\n");
        printf("4. Count nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Element %d inserted successfully!\n", data);
                break;
                
            case 2:
                displayList(head);
                break;
                
            case 3:
                displayReverseTraversal(head);
                break;
                
            case 4:
                printf("Total nodes in list: %d\n", countNodes(head));
                break;
                
            case 5:
                printf("\nFreeing memory and exiting...\n");
                freeList(&head);
                printf("Thank you for using the program!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}