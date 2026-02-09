#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, char c) {
    if(!isFull(s)) {
        s->arr[++(s->top)] = c;
    }
}

char pop(struct Stack* s) {
    if(!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

char peek(struct Stack* s) {
    if(!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

int getPrecedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    init(&s);
    int i, j = 0;
    
    for(i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        if(current == ' ')
            continue;
            
        if(isalnum(current)) {
            postfix[j++] = current;
        }
        else if(current == '(') {
            push(&s, current);
        }
        else if(current == ')') {
            while(!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        else if(isOperator(current)) {
            while(!isEmpty(&s) && getPrecedence(peek(&s)) >= getPrecedence(current)) {
                postfix[j++] = pop(&s);
            }
            push(&s, current);
        }
    }
    
    while(!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

struct IntStack {
    int top;
    int arr[MAX];
};

void initInt(struct IntStack* s) {
    s->top = -1;
}

int isEmptyInt(struct IntStack* s) {
    return s->top == -1;
}

void pushInt(struct IntStack* s, int val) {
    s->arr[++(s->top)] = val;
}

int popInt(struct IntStack* s) {
    if(!isEmptyInt(s)) {
        return s->arr[(s->top)--];
    }
    return 0;
}

int evaluatePostfix(char* postfix) {
    struct IntStack s;
    initInt(&s);
    
    for(int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];
        
        if(isdigit(current)) {
            pushInt(&s, current - '0');
        }
        else if(isOperator(current)) {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            int result;
            
            switch(current) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': 
                    result = 1;
                    for(int j = 0; j < val2; j++)
                        result *= val1;
                    break;
            }
            pushInt(&s, result);
        }
    }
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    // For evaluation, use simple numeric expression
    char testInfix[] = "2+3*4";
    char testPostfix[MAX];
    infixToPostfix(testInfix, testPostfix);
    printf("\nTest: %s converted to %s\n", testInfix, testPostfix);
    printf("Evaluation result: %d\n", evaluatePostfix(testPostfix));
    
    return 0;
}