#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->stack[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->stack[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->stack[s->top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(&s) != '(' && s.top != -1) {
                postfix[j++] = pop(&s);
            }
            if (peek(&s) == '(') {
                pop(&s); // Remove '('
            }
        } else if (isOperator(infix[i])) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}