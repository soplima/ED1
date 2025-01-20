#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, int* n) {
    int word_count = 0;
    const char* temp = str;
    while (*temp) {
        while (*temp == ' ') temp++;  
        if (*temp) {  
            word_count++;
            while (*temp && *temp != ' ') temp++;  
        }
    }

    char** words = (char**) malloc(word_count * sizeof(char*));
    if (words == NULL) {
        return NULL;  
    }

    int i = 0;
    temp = str;
    while (*temp) {
        while (*temp == ' ') temp++; 
        if (*temp) {
            const char* start = temp;
            while (*temp && *temp != ' ') temp++;  
            int length = temp - start; 

            words[i] = (char*) malloc((length + 1) * sizeof(char));
            if (words[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(words[j]);
                }
                free(words);
                return NULL;
            }

            strncpy(words[i], start, length);
            words[i][length] = '\0'; 
            i++;
        }
    }

    *n = word_count;

    return words; 
}
