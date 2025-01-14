
typedef struct {
 int size;
 int capacity;
 int *data;
}  VectorList;

bool list_is_full(VectorList* list){
	return (list ->capacity == list ->size);
}