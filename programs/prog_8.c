#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

long long comparisons = 0;
long long swaps = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;  
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void bubbleSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
  
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    mergeSortHelper(arr, 0, n - 1);
}

void displayStats(const char* sortName, long long comp, long long swp) {
    printf("\n--- %s Statistics ---\n", sortName);
    printf("Total Comparisons: %lld\n", comp);
    printf("Total Swaps: %lld\n", swp);
}

int main() {
    int n, choice;
    int originalArray[MAX], workingArray[MAX];
    
    printf("=== Sorting Algorithms Comparison ===\n\n");
    printf("Enter the number of random integers to generate (N): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid input! N must be between 1 and %d\n", MAX);
        return 1;
    }
    
    printf("\nGenerating %d random integers in range [1, 1000]...\n", n);
    generateRandomNumbers(originalArray, n);
    
    printf("\nOriginal array (first 20 elements): ");
    if (n <= 20) {
        printArray(originalArray, n);
    } else {
        printArray(originalArray, 20);
        printf("... and %d more elements\n", n - 20);
    }
   
    while (1) {
        printf("\n=== Choose a Sorting Algorithm ===\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Display Original Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 4) 
        {
            copyArray(originalArray, workingArray, n);
            
            printf("\nBefore sorting (first 20 elements): ");
            if (n <= 20) {
                printArray(workingArray, n);
            } else {
                printArray(workingArray, 20);
                printf("... and %d more elements\n", n - 20);
            }
        }
        
        switch (choice) {
            case 1:
                printf("\nSorting using Bubble Sort...\n");
                bubbleSort(workingArray, n);
                
                printf("\nAfter sorting (first 20 elements): ");
                if (n <= 20) {
                    printArray(workingArray, n);
                } else {
                    printArray(workingArray, 20);
                    printf("... and %d more elements\n", n - 20);
                }
                
                displayStats("Bubble Sort", comparisons, swaps);
                break;
                
            case 2:
                printf("\nSorting using Selection Sort...\n");
                selectionSort(workingArray, n);
                
                printf("\nAfter sorting (first 20 elements): ");
                if (n <= 20) {
                    printArray(workingArray, n);
                } else {
                    printArray(workingArray, 20);
                    printf("... and %d more elements\n", n - 20);
                }
                
                displayStats("Selection Sort", comparisons, swaps);
                break;
                
            case 3:
                printf("\nSorting using Insertion Sort...\n");
                insertionSort(workingArray, n);
                
                printf("\nAfter sorting (first 20 elements): ");
                if (n <= 20) {
                    printArray(workingArray, n);
                } else {
                    printArray(workingArray, 20);
                    printf("... and %d more elements\n", n - 20);
                }
                
                displayStats("Insertion Sort", comparisons, swaps);
                break;
                
            case 4:
                printf("\nSorting using Merge Sort...\n");
                mergeSort(workingArray, n);
                
                printf("\nAfter sorting (first 20 elements): ");
                if (n <= 20) {
                    printArray(workingArray, n);
                } else {
                    printArray(workingArray, 20);
                    printf("... and %d more elements\n", n - 20);
                }
                
                displayStats("Merge Sort", comparisons, swaps);
                break;
                
            case 5:
                printf("\nOriginal array (first 20 elements): ");
                if (n <= 20) {
                    printArray(originalArray, n);
                } else {
                    printArray(originalArray, 20);
                    printf("... and %d more elements\n", n - 20);
                }
                break;
                
            case 6:
                printf("\nExiting program...\n");
                return 0;
                
            default:
                printf("\nInvalid choice! Please try again\n");
        }
    }
    
    return 0;
}