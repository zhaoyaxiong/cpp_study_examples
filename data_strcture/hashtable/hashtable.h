//
// Created by hero on 2021/4/12.
//

#ifndef CPP_STUDY_EXAMPLES_HASHTABLE_H
#define CPP_STUDY_EXAMPLES_HASHTABLE_H
#include "list.h"
#include <stdlib.h>
typedef struct HashTable_
{
    int bucketNumber;
    int (*hash)(const void* key);
    int (*match)(const void* key1, const void* key2);
    void (*destroy)(void* data);
    int size;
    List *table;
}HashTable;

int hashtable_init(HashTable *hashTable, int bucketNumber, int (*hash)(const void* key),
                   int (*match)(const void* key1, const void* key2), void (*destroy)(void* data));
void hashtable_destroy(HashTable* hashTable);
int hashtable_insert(HashTable* hashTable, const void* data);
int hashtable_remove(HashTable* hashTable, void** data);
int hashtable_lookup(HashTable* hashTable, void** data);
#define hashtable_size(hashtable) ((hashtable)->size)
#endif //CPP_STUDY_EXAMPLES_HASHTABLE_H
