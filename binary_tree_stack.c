#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct stack {
    struct tree* data;
    struct stack* next;
};

void initialize(struct stack** top) {
    *top = NULL;
}

int isEmpty(struct stack* top) {
    return (top == NULL);
}

void push(struct stack** top, struct tree* value) {
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    if (newnode == NULL) return;
    newnode->data = value;
    newnode->next = *top;
    *top = newnode;
}

void pop(struct stack** top) {
    if (isEmpty(*top)) return;
    struct stack* temp = *top;
    *top = (*top)->next;
    free(temp);
}

struct tree* peek(struct stack* top) {
    if (isEmpty(top)) return NULL;
    return top->data;
}

struct tree* create_tree(){
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    int x;
    printf("Enter number : ");
    scanf("%d",&x);
    if(x == -1) return NULL;
    newnode->data = x;
    printf("Enter left child of %d ",x);
    newnode->left = create_tree();
    printf("Enter right child of %d ",x);
    newnode->right = create_tree(); 
    return newnode; 
}


void preorder(struct tree *root){
    if (root == NULL) return;
    struct stack* st;
    initialize(&st);
    push(&st, root);
    
    while (!isEmpty(st)) {
    struct tree* current = peek(st);
    pop(&st);
    printf("%d ",current->data);
    if (current->right) push(&st, current->right);
    if (current->left) push(&st, current->left);
}
}

void inorder(struct tree *root){
    if (root == NULL) return;
    struct stack* st;
    initialize(&st);

    struct tree *current = root;
    while(current != NULL || !isEmpty(st)){
        while (current != NULL) {
            push(&st, current);
            current = current->left;
        }
        current = peek(st);
        pop(&st);
        printf("%d ", current->data);
        current = current->right;
    }
}


void postorder(struct tree *root){
    if (root == NULL) return;
    struct stack *st1, *st2;
    initialize(&st1);
    initialize(&st2);

    push(&st1, root);

    while (!isEmpty(st1)) {
        struct tree* current = peek(st1);
        pop(&st1);
        push(&st2, current);

        if (current->left) push(&st1, current->left);
        if (current->right) push(&st1, current->right);
    }

    while (!isEmpty(st2)) {
        struct tree* temp = peek(st2);
        printf("%d ", temp->data);
        pop(&st2);
    }
}

int main(){
    struct tree* root;   
    root = create_tree(); 
    
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
    
    return 0;
}