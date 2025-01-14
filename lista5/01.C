#include <stdlib.h>
#include <stdio.h>

typedef struct {
 int size;
 int capacity;
 int *data;
}  VectorList;

bool list_is_empty(VectorList* list){
	return (list == NULL);
}


