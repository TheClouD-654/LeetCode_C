int lengthOfLongestSubstring(char* s) {
    int last[256] = {0};
    int start = 0, best = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if (last[c] > start) {
            start = last[c];
        }
        int len = i - start + 1;
        if (len > best) {
            best = len;
        }
        last[c] = i + 1;
    }
    return best;
}
