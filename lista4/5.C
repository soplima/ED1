#include <stdio.h>
#include <string.h>

typedef struct {
    long id;
    char name[51];
} Movie;

Movie read_movie(const char* filepath, int pos) {
    Movie movie = {0};

    FILE* file = fopen(filepath, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return movie;
    }

    if (fseek(file, pos * sizeof(Movie), SEEK_SET) != 0) {
        printf("Posição inválida.\n");
        fclose(file);
        return movie;
    }

    if (fread(&movie, sizeof(Movie), 1, file) != 1) {
        printf("Erro ao ler o arquivo.\n");
        fclose(file);
        return movie;
    }

    fclose(file);

    return movie;
}
