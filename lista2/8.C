#include <stdio.h>
#include <stdlib.h>

char* get_content(const char* filepath) {
    FILE* file = fopen(filepath, "r"); 

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

    size_t bytes_read = fread(content, 1, file_size, file);
    if (bytes_read != file_size) {
        free(content); 
        fclose(file);
        return NULL;
    }

    content[file_size] = '\0';

    fclose(file);  
    return content; 
}
