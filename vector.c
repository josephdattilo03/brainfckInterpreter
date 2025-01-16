#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
  char *data;
  size_t size;
  size_t capacity;
} CharVector;

void vectorInit(CharVector *v, size_t initalCapacity) {
  v->data = malloc(initalCapacity * sizeof(char));
  if (!v->data) {
    printf("Data could not be allocated.");
    exit(EXIT_FAILURE);
  }
  v->capacity = initalCapacity;
  v->size = 0;
}

void vectorResize(CharVector *v) {
  v->capacity = 2 * v->capacity;
  v->data = realloc(v->data, sizeof(char) * v->capacity);
  if (!v->data) {
    printf("Data could not be allocated.");
    free(v->data);
    exit(EXIT_FAILURE);
  }
}

void vectorAdd(CharVector *v, char value) {
  if (v->size >= v->capacity) {
    vectorResize(v);
  }
  v->data[v->size] = value;
}

char vectorGet(CharVector *v, size_t index) {
  if (index >= v->size) {
    printf("Index out of bounds.");
    exit(EXIT_FAILURE);
  }
  return v->data[index];
}

void vectorFree(CharVector *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}
