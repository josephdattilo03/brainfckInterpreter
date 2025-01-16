#include <stdlib.h>

struct Vector;

void vectorInit(Vector *v, size_t initalCapacity);
void vectorResize(Vector *v);
void vectorAdd(Vector *v, char value);
char vectorGet(Vector *v, size_t index);
void vectorFree(Vector *v);
