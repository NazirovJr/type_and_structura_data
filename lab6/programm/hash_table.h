#ifndef LAB6_HASH_TABLE_H
#define LAB6_HASH_TABLE_H
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define POW_RES 60

unsigned long hash_function(const char *str, int size);

void insert_hash_table(st_hash_table **p_hash_table, char *key);

int create_hash_node(st_hash_table table, char *buffer, int key);

//st_hash_table *create_hash_table(int size);

st_hash_table create_hash_table(FILE *f, int size, bool is_nkey);

int count_table_size(st_hash_table table);

void insertion_to_table(st_hash_table *table, char *buffer);

void init_table(st_hash_table *table, int size);

st_hash_table create_hash_table(FILE *f, const int size, bool is_nkey);

void init_hash_table(int hash_table_size, st_hash_table *hashTable);



#endif