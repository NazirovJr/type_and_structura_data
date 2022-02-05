

#include "hash_table.h"

unsigned long hash_function(const char *str, int size)
{
    unsigned long hash_key = 0;
    for (int j=0; str[j]; j++)
        hash_key += str[j];

    return hash_key % size;
}

unsigned long extra_hash_function(char *str, int size)
{
    unsigned long pow = 0;
    unsigned long hash_key = 0;
    do
    {
        hash_key += *str * pow;
        pow *= POW_RES;
    } while (*(str++) != '\0');

    return hash_key % size ;
}

int create_hash_node(st_hash_table table, char *buffer, int key)
{
    int avg_compare = 1;


    if (table.ptr[key].string == NULL) {
        table.ptr[key].string = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(table.ptr[key].string, buffer);
    }
    else
    {
        node_el *curr_node = table.ptr[key].next;
        node_el *prev_node = &table.ptr[key];

        avg_compare++;
        while (curr_node != NULL)
        {
            avg_compare++;
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        curr_node = malloc(sizeof(st_hash_table));
        curr_node->string =  malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(curr_node->string, buffer);
        curr_node->next = NULL;

        prev_node->next = curr_node;
    }

    return avg_compare;
}

void insert_hash_table(st_hash_table **p_hash_table, char *key) {
    unsigned long hash = hash_function(key, (*p_hash_table)->size);

    (*p_hash_table)->total_compare += create_hash_node(**p_hash_table, key, hash);
    (*p_hash_table)->size ++;
}

//st_hash_table *create_hash_table(int size)
//{
//    st_hash_table *p_hash_table = malloc(sizeof(st_hash_table));
//    p_hash_table->ptr = malloc(size * sizeof(node_el));
//    p_hash_table->size = size;
//    p_hash_table->total_compare = 0;
//
//    for (int i = 0; i < size ; ++i) {
//        p_hash_table->ptr[i].string = NULL;
//        p_hash_table->ptr[i].next = NULL;
//    }
//
//    return p_hash_table;
//}

static int create_node(st_hash_table table, char *buffer, int key)
{
    int avg_compare = 1;
    char *buffer_ptr = malloc((strlen(buffer) + 1) * sizeof(char));
    strncpy(buffer_ptr, buffer, strlen(buffer) + 1);


    if (table.ptr[key].string == NULL)
    {
        table.ptr[key].string = buffer_ptr;
    }
    else
    {
        node_el *curr_node = table.ptr[key].next;
        node_el *prev_node = &table.ptr[key];

        avg_compare++;
        while (curr_node != NULL)
        {
            avg_compare++;
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        curr_node = malloc(sizeof(node_el));
        curr_node->string = buffer_ptr;
        curr_node->next = NULL;

        prev_node->next = curr_node;
    }


    return avg_compare;
}


void init_table(st_hash_table *const table, const int size)
{
    table->ptr = malloc(size * sizeof(st_hash_table));
    table->size = size;

    for (int i = 0; i < size; i++)
    {
        table->ptr[i].string = NULL;
        table->ptr[i].next = NULL;
    }
}



void insertion_to_table(st_hash_table *const table, char *buffer)
{
    int key = hash_function(buffer, table->size);

    table->total_compare += create_node(*table, buffer, key);
    table->size++;
}

int count_table_size(st_hash_table table)
{
    int table_size = table.elements + table.size + 1;

    for (int i = 0; i < table.size; i++)
    {
        if (table.ptr[i].string != NULL)
        {
            table_size--;
        }
    }

    return table_size;
}

void init_hash_table(int hash_table_size, st_hash_table *hashTable) {
    hashTable->ptr = NULL;
    hashTable->total_compare = 0;
    hashTable->size = 0;
    hashTable->elements = 0;
    init_table(hashTable, hash_table_size);
}