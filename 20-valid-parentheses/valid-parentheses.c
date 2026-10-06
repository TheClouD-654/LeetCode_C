bool isValid(char* s) {
    char stack[10000];
    int top = 0;
    int round = 40, square = 91, curly = 123;
    for (int i = 0; s[i]; i++) {
        int c = s[i];
        if (c == round || c == square || c == curly) { stack[top++] = c; continue; }
        if (top == 0) return false;
        int open = stack[--top];
        if (c == round + 1 && open != round) return false;
        if (c == square + 2 && open != square) return false;
        if (c == curly + 2 && open != curly) return false;
    }
    return top == 0;
}