#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_separator(char c, const char* separators) {
    while (*separators) {
        if (c == *separators) {
            return 1;
        }
        separators++;
    }
    return 0;
}

char** get_words_sep(const char *path, const char* separators, int* words_count) {
    FILE* file = fopen(path, "r");  

    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* content = (char*) malloc(file_size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0'; 
    fclose(file);

    int max_words = 1000;
    char** words = (char**) malloc(max_words * sizeof(char*));
    if (!words) {
        free(content);
        return NULL;
    }

    int word_count = 0;
    char* token = strtok(content, " \n"); 

    while (token) {
        char* start = token;
        while (*start && is_separator(*start, separators)) {
            start++;
        }

        if (*start) {
            char* end = start + strlen(start) - 1;
            while (end >= start && is_separator(*end, separators)) {
                end--;
            }
            *(end + 1) = '\0';

            if (word_count >= max_words) {
                max_words *= 2;
                words = (char**) realloc(words, max_words * sizeof(char*));
                if (!words) {
                    free(content);
                    return NULL;
                }
            }

            words[word_count] = (char*) malloc(strlen(start) + 1);
            if (!words[word_count]) {
                free(content);
                return NULL;
            }

            strcpy(words[word_count], start);
            word_count++;
        }

        token = strtok(NULL, " \n");
    }

    free(content);

    *words_count = word_count;
    return words;
}
