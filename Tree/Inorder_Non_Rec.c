#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create new node
struct Node* newNode(int val) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

// Inorder traversal using stack
void inorder(struct Node* root) {
	struct Node* stack[100]; // stack size (adjust if needed)
	int top = -1;
	struct Node* temp = root;

	while (temp != NULL || top != -1) {
		// Reach the leftmost node
		while (temp != NULL) {
			stack[++top] = temp;
			temp = temp->left;
		}

		// Process top of stack
		temp = stack[top--];
		printf("%d ", temp->data);

		// Visit right subtree
		temp = temp->right;
	}
}

int main() {
	/*
	        1
	       / \
	      2   3
	     / \
	    4   5
	*/
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Inorder traversal: ");
	inorder(root);  // Output: 4 2 5 1 3

	return 0;
}