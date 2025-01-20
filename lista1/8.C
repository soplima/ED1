#include <stdio.h>

void print_vector2D(int m, int n, const int** v) {
    if (v == NULL) {
        printf("Matriz vazia.\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n"); 
    }
}
