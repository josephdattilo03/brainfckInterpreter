#ifndef STACK_H
#define STACK_H

typedef struct HashTable HashTable;
typedef struct HashTableEntry HashTableEntry;

HashTable *hashTableCreate(void);

void hashTableDestroy(HashTable *table);

void *hashTableGet(HashTable *table, const char *key);

const char hashTableSet(HashTable *table, const char *key, void *value);

#endif
