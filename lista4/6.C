#include <stdio.h>

typedef struct {
    long id;
    char name[51];
} Movie;

long find_movie(const char* filepath, long id) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return -1;
    }

    Movie movie;
    long pos = 0;

    while (fread(&movie, sizeof(Movie), 1, file) == 1) {
        if (movie.id == id) {
            fclose(file);
            return pos;
        }
        pos++;
    }

    fclose(file);
    return -1;
}
