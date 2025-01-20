#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long id;
    char name[51];
} Movie;

void write_all_movies(const char* filepath, int n, const Movie* v) {
    FILE* file = fopen(filepath, "wb");
    if (!file) {
        printf("Erro ao abrir ou criar o arquivo '%s'.\n", filepath);
        return;
    }

    for (int i = 0; i < n; i++) {
        fwrite(&v[i], sizeof(Movie), 1, file);
    }

    fclose(file);
    printf("Dados gravados com sucesso no arquivo '%s'.\n", filepath);
}
