#include <stdlib.h>
#include <string.h>

char* concat_string(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL; 
    }

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*) malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; 
    }

    strcpy(result, str1);

    strcat(result, str2);

    return result; 
}