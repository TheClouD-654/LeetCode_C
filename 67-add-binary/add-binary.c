#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int i = (int)strlen(a) - 1;
    int j = (int)strlen(b) - 1;
    int capacity = (i > j ? i : j) + 3;
    char* result = malloc(capacity);
    int length = 0, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[length++] = '0' + sum % 2;
        carry = sum / 2;
    }
    for (int left = 0, right = length - 1; left < right; ++left, --right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    result[length] = '\0';
    return result;
}
