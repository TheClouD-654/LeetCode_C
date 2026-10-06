char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++)
        while (len > 0 && strncmp(strs[0], strs[i], len) != 0) len--;
    char* ans = malloc(len + 1);
    memcpy(ans, strs[0], len);
    ans[len] = '\0';
    return ans;
}