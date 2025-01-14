typedef struct {
 int size;
 int capacity;
 int *data;
}  VectorList;

#include <stdlib.h>
#include <stdio.h>

VectorList* list_from_vector(int n, int* vet){

VectorList* list = (VectorList*)malloc(sizeof(VectorList));
if (!list){
return NULL;
}

list -> capacity = 2 * n;

list -> data = (int*)malloc(list -> capacity * sizeof(int));
if (!list->data){
return NULL;
}

for (int i = 0; i < n; i++){
list -> data[i] = vet[i];
}

return list;

}
