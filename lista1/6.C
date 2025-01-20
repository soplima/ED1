#include <stdlib.h>
#include <stdbool.h>

bool exists_in_array(int value, int size, const int* array) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

int* array_union(int n1, const int* v1, int n2, const int* v2, int* result_size) {
    if (v1 == NULL || v2 == NULL || n1 < 0 || n2 < 0) {
        *result_size = 0;
        return NULL; 
    }

    int max_size = n1 + n2;
    int* union_array = (int*) malloc(max_size * sizeof(int));
    if (union_array == NULL) {
        *result_size = 0;
        return NULL; 
    }

    int count = 0;

    for (int i = 0; i < n1; i++) {
        union_array[count++] = v1[i];
    }

    for (int i = 0; i < n2; i++) {
        if (!exists_in_array(v2[i], count, union_array)) {
            union_array[count++] = v2[i];
        }
    }

    *result_size = count;
    union_array = (int*) realloc(union_array, count * sizeof(int));

    return union_array; 
}
