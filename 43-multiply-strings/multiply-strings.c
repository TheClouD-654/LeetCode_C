char* multiply(char* num1, char* num2) {
    int m = strlen(num1), n = strlen(num2);
    int* digits = calloc(m + n, sizeof(int));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + digits[i + j + 1];
            digits[i + j + 1] = sum % 10;
            digits[i + j] += sum / 10;
        }
    }
    char* result = malloc(m + n + 1);
    int start = 0, pos = 0;
    while (start < m + n - 1 && digits[start] == 0) start++;
    while (start < m + n) result[pos++] = digits[start++] + '0';
    result[pos] = 0;
    free(digits);
    return result;
}