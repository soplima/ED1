#include <stdio.h>

void write_array(const char* filepath, int n, const int* v) {
    FILE* file = fopen(filepath, "w");

    if (!file) {
        printf("Erro ao abrir ou criar o arquivo '%s'.\n", filepath);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", v[i]); 
    }

    fclose(file);
    printf("Conteúdo gravado com sucesso no arquivo '%s'.\n", filepath);
}
