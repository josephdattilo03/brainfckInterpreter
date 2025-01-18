#include "hashtable.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

struct HashTableEntry {
  const char *key;
  void *value;
};

struct HashTable {
  HashTableEntry *entries;
  size_t capacity;
  size_t length;
};

HashTable *hashTableCreate() {
  HashTable *table = malloc(sizeof(HashTable));
  if (table == NULL) {
    exit(EXIT_FAILURE);
  }
  table->capacity = INITIAL_CAPACITY;
  table->length = 0;

  table->entries = calloc(table->capacity, sizeof(HashTableEntry));
  if (table->entries == NULL) {
    free(table);
    exit(EXIT_FAILURE);
  }
  return table;
}

void hashTableDestroy(HashTable *table) {
  for (int i = 0; i < table->capacity; i++) {
    free((void *)table->entries[i].key);
  }
  free(table->entries);
  free(table);
}

static uint64_t hashKey(const char *key) {
  uint64_t hash = FNV_OFFSET;
  for (const char *p = key; *p; p++) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
}

void *hashTaqbleGet(HashTable *table, const char *key) {
  uint64_t hash = hashKey(key);
  size_t index = (size_t)hash & (uint64_t)(table->capacity - 1);
  while (table->entries[index].key != NULL) {
    if (strcmp(key, table->entries[index].key)) {
      return table->entries[index].value;
    }
    index++;
    if (index >= table->capacity) {
      index = 0;
    }
  }
  return NULL;
}

const char hashTableSet(HashTable *table, const char *key, void *value) {
  return 'a';
}
