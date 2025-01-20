#include <stdlib.h>
#include <stdbool.h>

bool exists_in_array(const int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int* array_intersection(int n1, const int* v1, int n2, const int* v2, int* intersection_size) {
    if (v1 == NULL || v2 == NULL || n1 < 0 || n2 < 0) {
        *intersection_size = 0;
        return NULL;
    }

    int max_size = (n1 < n2) ? n1 : n2;

    int* intersection_array = (int*) malloc(max_size * sizeof(int));
    if (intersection_array == NULL) {
        *intersection_size = 0;
        return NULL; 
    }

    int count = 0;
    for (int i = 0; i < n1; i++) {
        if (exists_in_array(v2, n2, v1[i])) {
            intersection_array[count++] = v1[i];
        }
    }

    *intersection_size = count;

    intersection_array = (int*) realloc(intersection_array, count * sizeof(int));

    return intersection_array; 
}
