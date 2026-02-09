# Documentation for prog_8.c

## Data Structures Used

### Arrays
- `originalArray[]`: Stores the randomly generated numbers
- `workingArray[]`: Copy of original array used for sorting
- This way, we can sort multiple times with different algorithms

### Counters
- `comparisons`: Counts how many times elements are compared
- `swaps`: Counts how many times elements are moved/swapped

## Sorting Algorithms Implemented

### 1. Bubble Sort
- **How it works**: Repeatedly compares adjacent elements and swaps them if they're in wrong order
- **Simple idea**: Largest element "bubbles up" to the end in each pass
- **Time Complexity**: O(n²)

### 2. Selection Sort
- **How it works**: Finds the minimum element and places it at the beginning
- **Simple idea**: Select the smallest, put it first, repeat
- **Time Complexity**: O(n²)

### 3. Insertion Sort
- **How it works**: Builds sorted array one element at a time
- **Simple idea**: Like sorting playing cards in your hand
- **Time Complexity**: O(n²)

### 4. Merge Sort
- **How it works**: Divides array into halves, sorts them, then merges
- **Simple idea**: Divide and conquer
- **Time Complexity**: O(n log n) - Fastest among these

## Functions Implemented

### 1. generateRandomNumbers()
- Creates N random numbers between 1 and 1000
- Uses `rand()` function with time-based seed

### 2. copyArray()
- Copies elements from one array to another
- Needed to preserve original array for multiple sorting attempts

### 3. printArray()
- Displays array elements
- Shows first 20 elements if array is large

### 4. swap()
- Swaps two elements
- Increments swap counter

### 5. bubbleSort()
- Implements bubble sort algorithm
- Counts comparisons and swaps

### 6. selectionSort()
- Implements selection sort algorithm
- Counts comparisons and swaps

### 7. insertionSort()
- Implements insertion sort algorithm
- Counts comparisons and swaps

### 8. mergeSort() and merge()
- Implements merge sort algorithm
- Counts comparisons and swaps

### 9. displayStats()
- Shows total comparisons and swaps for the chosen algorithm

## Main() function Organization

1. **Get N**: Ask user how many random numbers to generate
2. **Generate**: Create N random numbers
3. **Display Original**: Show the unsorted array
4. **Menu Loop**:
   - Option 1-4: Choose a sorting algorithm
   - Option 5: Display original array again
   - Option 6: Exit
5. **For Each Sort**:
   - Copy original array
   - Apply sorting algorithm
   - Display before and after
   - Show statistics (comparisons and swaps)

## Sample Input/Output

### Input
```
Enter the number of random integers to generate (N): 10
Generated numbers: 456 123 789 234 567 890 345 678 901 12

Choose sorting algorithm: 1 (Bubble Sort)
```

### Output
```

Enter the number of random integers to generate (N): 10

Generating 10 random integers in range [1, 1000]...

Original array (first 20 elements): 456 123 789 234 567 890 345 678 901 12 

=== Choose a Sorting Algorithm ===
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Display Original Array
6. Exit
Enter your choice: 1

Before sorting (first 20 elements): 456 123 789 234 567 890 345 678 901 12 

Sorting using Bubble Sort...

After sorting (first 20 elements): 12 123 234 345 456 567 678 789 890 901 

Total Comparisons: 45
Total Swaps: 25

=== Choose a Sorting Algorithm ===
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Display Original Array
6. Exit
Enter your choice: 4

Before sorting (first 20 elements): 456 123 789 234 567 890 345 678 901 12 

Sorting using Merge Sort...

After sorting (first 20 elements): 12 123 234 345 456 567 678 789 890 901 

Total Comparisons: 19
Total Swaps: 33

=== Choose a Sorting Algorithm ===
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Display Original Array
6. Exit
Enter your choice: 6

Exiting program...
```

