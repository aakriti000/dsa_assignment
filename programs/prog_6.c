#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
   
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
      
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;       
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
     if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayHeapTree(int arr[], int n, const char* heapType) {
    printf("\n%s in Tree Format:\n", heapType);
    printf("----------------------------------\n");
    
    int level = 0;
    int elementsInLevel = 1;
    int index = 0;
    
    while (index < n) {
        for (int i = 0; i < (1 << (4 - level)) - 1; i++) {
            printf("  ");
        }
        
        for (int i = 0; i < elementsInLevel && index < n; i++) {
            printf("%4d", arr[index]);
            index++;
            
            if (i < elementsInLevel - 1 && index < n) {
                for (int j = 0; j < (1 << (5 - level)) - 1; j++) {
                    printf("  ");
                }
            }
        }
        printf("\n");
        
        level++;
        elementsInLevel *= 2;
        
        if (level > 4) break; 
    }
    printf("----------------------------------\n");
}

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) 
    {
        if (2 * i + 1 < n && arr[i] < arr[2 * i + 1])
            return 0;
      
        if (2 * i + 2 < n && arr[i] < arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) 
    {
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            return 0;
        
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

void displayHeapProperties(int arr[], int n, const char* heapType) {
    printf("\n%s Properties:\n", heapType);
    printf("Index\tValue\tParent\tLeft Child\tRight Child\n");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", i, arr[i]);
   
        if (i == 0)
            printf("-\t");
        else
            printf("%d\t", arr[(i - 1) / 2]);
        
        if (2 * i + 1 < n)
            printf("%d\t\t", arr[2 * i + 1]);
        else
            printf("-\t\t");
       
        if (2 * i + 2 < n)
            printf("%d\n", arr[2 * i + 2]);
        else
            printf("-\n");
    }
}

int main() {
    int n, i, choice;
    int arr[MAX], tempArr[MAX];
    
    printf("=== Min Heap and Max Heap Implementation ===\n\n");
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements!\n");
        return 1;
    }
   
    printf("Enter %d elements (unsorted):\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    printArray(arr, n);
    
    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Build and Display Max Heap\n");
        printf("2. Build and Display Min Heap\n");
        printf("3. Display Original Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    tempArr[i] = arr[i];
                }
              
                buildMaxHeap(tempArr, n);
                
                printf("\n--- MAX HEAP ---\n");
                printf("Max Heap Array: ");
                printArray(tempArr, n);
               
                if (isMaxHeap(tempArr, n)) {
                    printf("✓ Max Heap property verified!\n");
                } else {
                    printf("✗ Not a valid Max Heap!\n");
                }
              
                displayHeapTree(tempArr, n, "Max Heap");
              
                displayHeapProperties(tempArr, n, "Max Heap");
                
                break;
                
            case 2:
                for (i = 0; i < n; i++) {
                    tempArr[i] = arr[i];
                }
               
                buildMinHeap(tempArr, n);
                
                printf("\n--- MIN HEAP ---\n");
                printf("Min Heap Array: ");
                printArray(tempArr, n);
               
                if (isMinHeap(tempArr, n)) {
                    printf("✓ Min Heap property verified!\n");
                } else {
                    printf("✗ Not a valid Min Heap!\n");
                }
               
                displayHeapTree(tempArr, n, "Min Heap");
                displayHeapProperties(tempArr, n, "Min Heap");
                
                break;
                
            case 3:
                printf("\nOriginal Array: ");
                printArray(arr, n);
                break;
                
            case 4:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}