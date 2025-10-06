#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

// Function to check if two characters are a matching pair
int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

void areParenthesesBalanced(char exp[]) {
    struct Stack s;
    initialize(&s);
    int i = 0;

    // Traverse the expression string
    while (exp[i]) {
        // If the character is an opening bracket, push it onto the stack
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&s, exp[i]);
        }

        // If it is a closing bracket, pop from stack and check for matching pair
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // If stack is empty, there is no matching opening bracket
            if (isEmpty(&s)) {
                printf("The parentheses are NOT balanced.\n");
                return;
            }

            // Pop the top element and check if it matches the current closing bracket
            if (!isMatchingPair(pop(&s), exp[i])) {
                printf("The parentheses are NOT balanced.\n");
                return;
            }
        }
        i++;
    }

    // After traversal, if the stack is empty, then the expression is balanced
    if (isEmpty(&s)) {
        printf("The parentheses are balanced.\n");
    } else {
        // If stack is not empty, there are unmatched opening brackets
        printf("The parentheses are NOT balanced.\n");
    }
}

int main() {
    char expression1[] = "{()}[]";
    printf("Checking Expression: %s\n", expression1);
    areParenthesesBalanced(expression1);

    printf("\n");

    char expression2[] = "([)]";
    printf("Checking Expression: %s\n", expression2);
    areParenthesesBalanced(expression2);
    
    printf("\n");

    char expression3[] = "{{([()])}}";
    printf("Checking Expression: %s\n", expression3);
    areParenthesesBalanced(expression3);

    return 0;
}