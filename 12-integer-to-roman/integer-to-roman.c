char* intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
    char* ans = malloc(32);
    int k = 0;
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            for (int j = 0; symbols[i][j] != '\0'; j++) {
                ans[k++] = symbols[i][j];
            }
            num -= values[i];
        }
    }
    ans[k] = '\0';
    return ans;
}
