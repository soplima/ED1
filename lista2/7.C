#include <stdio.h>

int save_lines(const char* filepath, int n, const char text_lines[n][51]) {
    FILE* file = fopen(filepath, "w");  

    if (!file) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (fputs(text_lines[i], file) == EOF || fputc('\n', file) == EOF) {
            fclose(file); 
            return 0; 
        }
    }

    fclose(file); 
    return 1; 
}
