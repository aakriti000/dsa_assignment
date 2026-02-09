# Documentation for prog_1.c

## Balanced Parentheses Using Stack
This program takes any mathematical expression such as a+(b-c) as input and checks if the the number of parentheses and their order in the expression is valid or not.

## Data Structure Definition

This program uses a **stack** data structure to check whether a given mathematical
expression has balanced parentheses.

The stack is implemented using:
- An array of characters to store parentheses
- An integer variable `top` to keep track of index of the top element of the stack in the array with `top = -1` indicating that the stack is empty.

The stack follows the **LIFO (Last In First Out)** principle, which is suitable for
checking nested parentheses.


## Description of Functions

- `initStack()`  
  Initializes the stack by setting the top index to -1.

- `isEmpty()`  
  Checks whether the stack is empty.

- `push()`  
  Inserts an opening parenthesis into the stack.

- `pop()`  
  Removes and returns the top element from the stack.

- `isMatchingPair()`  
  Checks whether an opening and closing parenthesis match correctly.

- `areParenthesesBalanced()`  
  Traverses the expression character by character, pushes opening parentheses
  into the stack, and pops them when a closing parenthesis is found.
  Returns 1 if balanced, otherwise 0.


## Organization of main() Function

The `main()` function:
1. Takes an expression as input from the user.
2. Calls `areParenthesesBalanced()` to check correctness.
3. Displays whether the expression has balanced parentheses or not.


## Sample Output
**Sample Input 1**
```bash
Enter any expression with parentheses: a + (b - c)
```
**Sample output 1**
```bash
The expression has balanced parentheses.
```
**Sample Input 2**
```bash
Enter any expression with parentheses: m+[a-b*(c+d*{m)]
```
**Sample output 2**
```bash
The expression does NOT have balanced parentheses.
```
**Sample Input 3**
```bash
Enter any expression with parentheses: a+(b-c)*(d
```
**Sample output 3**
```bash
The expression does NOT have balanced parentheses.


