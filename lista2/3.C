#include <stdio.h>

int print_content(const char* filepath) {
    FILE* file = fopen(filepath, "r");  

    if (!file) {
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);  
    }

    fclose(file); 
    return 1;
}
