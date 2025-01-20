#include <stdio.h>
#include <stdlib.h>

int* read_array(const char* filepath, int* n) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s'.\n", filepath);
        return NULL;
    }

    int count = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        count++;
    }

    rewind(file);

    int* v = (int*)malloc(count * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &v[i]);
    }

    fclose(file);
    
    *n = count;
    return v;
}
