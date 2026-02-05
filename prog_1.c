#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// stack structure
struct Stack {
    char items[MAX];
    int top;
};

// initializing stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// push element into stack
void push(struct Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = ch;
}

// pop element from stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top--];
}

// function to check matching parentheses
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

// function to check balanced parentheses
int areParenthesesBalanced(char expr[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // push the opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s))
                return 0;

            char top = pop(&s);
            if (!isMatchingPair(top, ch))
                return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);

    if (areParenthesesBalanced(expr))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression does NOT have balanced parentheses.\n");

    return 0;
}
