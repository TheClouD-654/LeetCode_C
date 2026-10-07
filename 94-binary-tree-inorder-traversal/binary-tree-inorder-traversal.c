#include <stdlib.h>

static int countNodes(struct TreeNode* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

static void inorder(struct TreeNode* node, int* output, int* index) {
    if (!node) return;
    inorder(node->left, output, index);
    output[(*index)++] = node->val;
    inorder(node->right, output, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int count = countNodes(root);
    *returnSize = 0;
    if (count == 0) return NULL;
    int* output = malloc(count * sizeof(int));
    inorder(root, output, returnSize);
    return output;
}
