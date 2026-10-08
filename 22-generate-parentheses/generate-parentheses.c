void build(char** ans, int* count, char* path, int n, int open, int close) {
    int pos = open + close;
    if (pos == 2 * n) {
        path[pos] = '\0';
        ans[*count] = malloc(pos + 1);
        strcpy(ans[*count], path);
        (*count)++;
        return;
    }
    if (open < n) {
        path[pos] = '(';
        build(ans, count, path, n, open + 1, close);
    }
    if (close < open) {
        path[pos] = ')';
        build(ans, count, path, n, open, close + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 1 << (2 * n);
    char** ans = malloc(capacity * sizeof(char*));
    char* path = malloc(2 * n + 1);
    *returnSize = 0;
    build(ans, returnSize, path, n, 0, 0);
    free(path);
    return ans;
}