#include <stdio.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int add_movie(const char* filepath, Movie movie) {
    FILE* file = fopen(filepath, "ab");  
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return 0;
    }

    if (fwrite(&movie, sizeof(Movie), 1, file) != 1) {
        printf("Erro ao escrever o filme no arquivo.\n");
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}
