#include <stdio.h>
#include <stdlib.h>

int** transpose(int m, int n, int v[m][n]) {
    int** transposed = (int**) malloc(n * sizeof(int*));
    if (transposed == NULL) {
        return NULL; 
    }

    for (int i = 0; i < n; i++) {
        transposed[i] = (int*) malloc(m * sizeof(int));
        if (transposed[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(transposed[j]);
            }
            free(transposed);
            return NULL;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = v[i][j];
        }
    }

    return transposed; 
}
