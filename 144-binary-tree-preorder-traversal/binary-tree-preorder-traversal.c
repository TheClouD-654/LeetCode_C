#include <stdlib.h>

static int countNodes(struct TreeNode* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

static void preorder(struct TreeNode* node, int* output, int* index) {
    if (!node) return;
    output[(*index)++] = node->val;
    preorder(node->left, output, index);
    preorder(node->right, output, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int count = countNodes(root);
    *returnSize = 0;
    if (count == 0) return NULL;
    int* output = malloc(count * sizeof(int));
    preorder(root, output, returnSize);
    return output;
}
