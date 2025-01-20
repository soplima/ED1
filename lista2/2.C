#include <stdio.h>

int check_or_create(const char* filepath) {
    FILE* file = fopen(filepath, "r");

    if (file) {
        fclose(file); 
        return 1;
    } else {
        file = fopen(filepath, "w"); 

        if (file) {
            fclose(file);  
            return 1;
        }
    }

    return 0;
}
