char* convert(char* s, int numRows) {
    int n = strlen(s);
    char* ans = malloc(n + 1);
    if (numRows == 1 || numRows >= n) {
        strcpy(ans, s);
        return ans;
    }
    int cycle = 2 * numRows - 2;
    int k = 0;
    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < n; i += cycle) {
            ans[k++] = s[i];
            int j = i + cycle - 2 * row;
            if (row > 0 && row < numRows - 1 && j < n) {
                ans[k++] = s[j];
            }
        }
    }
    ans[k] = '\0';
    return ans;
}
