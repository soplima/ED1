#include <stdlib.h>

int** create_vector2D(int m, int n) {
    int** matrix = (int**) malloc(m * sizeof(int*));
    if (matrix == NULL) {
        return NULL; 
    }

    int value = 1;

    for (int i = 0; i < m; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }

        for (int j = 0; j < n; j++) {
            matrix[i][j] = value++; 
        }
    }

    return matrix; 
}
