char** letterCombinations(char* digits, int* returnSize) {
    char* map[] = {"",    "",    "abc",  "def", "ghi",
                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = strlen(digits);
    *returnSize = 0;
    if (n == 0) {
        return NULL;
    }
    int total = 1;
    for (int i = 0; i < n; i++) {
        total *= strlen(map[digits[i] - '0']);
    }
    char** ans = malloc(total * sizeof(char*));
    for (int k = 0; k < total; k++) {
        ans[k] = malloc(n + 1);
        int value = k;
        for (int i = n - 1; i >= 0; i--) {
            char* letters = map[digits[i] - '0'];
            int count = strlen(letters);
            ans[k][i] = letters[value % count];
            value /= count;
        }
        ans[k][n] = '\0';
    }
    *returnSize = total;
    return ans;
}
