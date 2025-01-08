char* clearDigits(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int top = -1; 

    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (top >= 0) {
                top--; 
            }
        } else {
            result[++top] = s[i];
        }
    }

    result[top + 1] = '\0'; 
    return result;
}
