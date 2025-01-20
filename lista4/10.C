#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int insert_sorted(const char* filepath, Movie movie) {
    FILE* file = fopen(filepath, "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return 0;
    }

    Movie temp_movie;
    long current_pos;
    int inserted = 0;
    
    while (fread(&temp_movie, sizeof(Movie), 1, file) == 1) {
        if (temp_movie.id > movie.id) {
            current_pos = ftell(file); 
            
            fseek(file, current_pos - sizeof(Movie), SEEK_SET);
            
            if (fwrite(&movie, sizeof(Movie), 1, file) != 1) {
                printf("Erro ao escrever o novo filme.\n");
                fclose(file);
                return 0;
            }

            inserted = 1; 
            break;
        }
    }

    if (!inserted) {
        fseek(file, 0, SEEK_END);
        
        if (fwrite(&movie, sizeof(Movie), 1, file) != 1) {
            printf("Erro ao escrever o novo filme no final.\n");
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}
