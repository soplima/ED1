#include <stdio.h>

typedef struct {
    long id;
    char name[51];
} Movie;

int count_movies(const char* filepath) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return -1;
    }

    int count = 0;
    Movie movie;
    while (fread(&movie, sizeof(Movie), 1, file) == 1) {
        count++;
    }

    fclose(file);

    return count;
}
