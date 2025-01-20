#include <stdio.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int update_movie(const char* filepath, Movie movie) {
    FILE* file = fopen(filepath, "r+b"); 
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return 0;
    }

    Movie temp_movie;
    int found = 0; 

    while (fread(&temp_movie, sizeof(Movie), 1, file) == 1) {
        if (temp_movie.id == movie.id) {
            fseek(file, -sizeof(Movie), SEEK_CUR); 
            if (fwrite(&movie, sizeof(Movie), 1, file) != 1) {
                printf("Erro ao atualizar o filme no arquivo.\n");
                fclose(file);
                return 0;
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Filme com ID %ld não encontrado.\n", movie.id);
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;  
}
