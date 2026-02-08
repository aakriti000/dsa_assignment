# Documentation for prog_2.c

## Data Structures Used

### 1. Character Stack
Used during **infix to postfix conversion**.

- Implemented using an array
- Stores operators and parentheses
- Follows **LIFO (Last In First Out)** principle

```c
struct Stack {
    int top;
    char arr[MAX];
};
```

---

### 2. Integer Stack
Used during **postfix expression evaluation**.

- Stores integer operands
- Performs arithmetic operations using stack-based processing

```c
struct IntStack {
    int top;
    int arr[MAX];
};
```

---

## Functional Description

### Infix to Postfix Conversion

The conversion follows standard rules:
- Operands are directly appended to postfix expression
- Operators are pushed into the stack based on precedence
- Parentheses control the order of operations
- Remaining operators are popped from stack at the end

Operator precedence:
- `^` (highest)
- `*`, `/`
- `+`, `-`

---

### Postfix Evaluation

- Operands are pushed onto an integer stack
- Operators pop two operands
- The operation is performed
- The result is pushed back to the stack
- Final stack value gives the evaluated result

---

## Description of Functions

### Character Stack Functions
- `init()` – Initializes the stack
- `push()` – Pushes an operator or parenthesis
- `pop()` – Pops top element from stack
- `peek()` – Returns the top element without removing it
- `getPrecedence()` – Returns precedence of operators
- `isOperator()` – Checks whether a character is an operator

---

### Conversion Function
- `infixToPostfix()`  
  Converts the infix expression into postfix form using stack and precedence rules.

---

### Integer Stack Functions
- `initInt()` – Initializes integer stack
- `pushInt()` – Pushes integer value
- `popInt()` – Pops integer value from stack

---

### Evaluation Function
- `evaluatePostfix()`  
  Evaluates a postfix expression using integer stack operations.

---

## Organization of `main()` Function

1. Accepts infix expression from the user
2. Converts infix expression to postfix
3. Displays the postfix expression
4. Demonstrates evaluation using a numeric expression
5. Displays the evaluation result

---

## Sample Output

### Input
```
Enter infix expression: a+b*c
```

### Output
```
Postfix expression: abc*+

Test: 2+3*4 converted to 234*+
Evaluation result: 14
```

---

## Compilation and Execution

### Compile
```
gcc prog_2.c -o prog_2
```

### Run
```
./prog_2.exe(on windows)
```

