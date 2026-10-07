#include <stdlib.h>

static int countNodes(struct TreeNode* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

static void postorder(struct TreeNode* node, int* output, int* index) {
    if (!node) return;
    postorder(node->left, output, index);
    postorder(node->right, output, index);
    output[(*index)++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int count = countNodes(root);
    *returnSize = 0;
    if (count == 0) return NULL;
    int* output = malloc(count * sizeof(int));
    postorder(root, output, returnSize);
    return output;
}
