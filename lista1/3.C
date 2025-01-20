#include <stdlib.h>
#include <string.h>

char* copy_string(const char* str){
 if (str == NULL) {
        return NULL; 
    }

    size_t length = strlen(str) + 1;

    char* copy = (char*) malloc(length * sizeof(char));
    if (copy == NULL) {
        return NULL; 
    }

    strcpy(copy, str);

    return copy; 
}