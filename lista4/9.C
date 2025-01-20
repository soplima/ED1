#include <stdio.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int delete_movie(const char* filepath, long id) {
    FILE* file = fopen(filepath, "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return 0;
    }

    Movie temp_movie;
    int found = 0; 

    while (fread(&temp_movie, sizeof(Movie), 1, file) == 1) {
        if (temp_movie.id == id) {
            fseek(file, -sizeof(Movie), SEEK_CUR);  
            temp_movie.id = -1;
            if (fwrite(&temp_movie, sizeof(Movie), 1, file) != 1) {
                printf("Erro ao marcar o filme como removido.\n");
                fclose(file);
                return 0;
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Filme com ID %ld não encontrado.\n", id);
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}
