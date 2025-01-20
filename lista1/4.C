#include <stdlib.h>
#include <string.h>

char* copy_reverse(const char* str) {
    if (str == NULL) {
        return NULL; 
    }

    size_t length = strlen(str) + 1;

    char* reverse = (char*) malloc(length * sizeof(char));
    if (reverse == NULL) {
        return NULL; 
    }

    for (size_t i = 0; i < length; i++) {
        reverse[i] = str[length - 1 - i];
    }

    reverse[length] = '\0';

    return reverse; 
}

