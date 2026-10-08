int myAtoi(char* s) {
    int i = 0, sign = 1;
    long long value = 0;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }
    long long limit = sign == 1 ? 2147483647LL : 2147483648LL;
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        if (value > (limit - digit) / 10) {
            return sign == 1 ? 2147483647 : (-2147483647 - 1);
        }
        value = value * 10 + digit;
        i++;
    }
    return (int)(sign * value);
}
