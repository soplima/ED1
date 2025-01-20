#include <stdio.h>

int file_exists(const char* filepath) {
    FILE* file = fopen(filepath, "r");  
    if (file) {
        fclose(file);  
        return 1;  
    }
    return 0;  
}
