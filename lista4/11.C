#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int defrag(const char* filepath) {
    FILE* file = fopen(filepath, "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return 0;  
    }

    Movie current_movie;
    long write_pos = 0; 
    long read_pos = 0; 

    while (fread(&current_movie, sizeof(Movie), 1, file) == 1) {
        if (current_movie.id != -1) {
            fseek(file, write_pos * sizeof(Movie), SEEK_SET);

            if (fwrite(&current_movie, sizeof(Movie), 1, file) != 1) {
                printf("Erro ao escrever o filme no arquivo.\n");
                fclose(file);
                return 0; 
            }

            write_pos++;
        }

        read_pos++;
    }

    fclose(file);
    return 1;  
}
