#include <stdio.h>

int save_string(const char* filepath, const char* text) {
    FILE* file = fopen(filepath, "w");  

    if (!file) {
        return 0;
    }

    if (fputs(text, file) == EOF) {
        fclose(file);  
        return 0;  
    }

    fclose(file);  
    return 1;
}
