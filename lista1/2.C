#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); 
}

int* get_largest(int n, int* v, int max) {
    if (n <= 0 || max <= 0 || v == NULL || max > n) {
        return NULL;
    }
    
    qsort(v, n, sizeof(int), compare);

    int* largest = (int*) malloc(max * sizeof(int));
    if (largest == NULL) {
        return NULL; 
    }

    for (int i = 0; i < max; i++) {
        largest[i] = v[i];
    }

    return largest; 
}

void print_vector(int n, int* v) {
    if (v == NULL) {
        printf("Vetor vazio.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}