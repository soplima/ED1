#include <stdlib.h>


int* create_vector(int n) {
    int* vector = (int*) malloc(n * sizeof(int));

    if (vector == NULL){
        return NULL;
    }

    for (int i = 0; i < n; i ++){
        vector[i] = 0;
    }

}