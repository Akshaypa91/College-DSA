#include <stdio.h>
#include <stdlib.h>

//Method-1 by Stack
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    stack<struct TreeNode*> st;
    struct TreeNode* temp = root;

    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        arr[(*returnSize)++] = temp->val;
        temp = temp->right;
    }
    return arr;
}

//Method-2 by Recursion
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    inorderHelper(root, arr, returnSize);
    return arr;
}

void inorderHelper(struct TreeNode* root, int* arr, int* returnSize) {
    if (root == NULL) return;
    inorderHelper(root->left, arr, returnSize);
    arr[(*returnSize)++] = root->val;
    inorderHelper(root->right, arr, returnSize);
}

int main() {

    return 0;
}