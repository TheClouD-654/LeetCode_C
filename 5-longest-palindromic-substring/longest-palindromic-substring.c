char* longestPalindrome(char* s) {
    int n = strlen(s);
    int start = 0, best = 0;
    for (int i = 0; i < n; i++) {
        for (int even = 0; even <= 1; even++) {
            int l = i, r = i + even;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > best) {
                    start = l;
                    best = r - l + 1;
                }
                l--;
                r++;
            }
        }
    }
    char* ans = malloc(best + 1);
    memcpy(ans, s + start, best);
    ans[best] = '\0';
    return ans;
}
