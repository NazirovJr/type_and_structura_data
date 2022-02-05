#ifndef LAB6_IO_H
#define LAB6_IO_H


#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <stdbool.h>
#include <string.h>
#include "lib_tree_oper.h"
#include "hash_table.h"
#include "errors.h"

#define ERR_IO 3
#define BUF_SIZE 8
#define ASCII_APOSTROPHE 39
#define N 10000
#define MAX_HEIGHT_SIZE 10

int read_file(FILE *f, st_tree **avl_tree, st_tree **b_tree, st_hash_table **p_hash_table, int len_c);

int get_size(FILE *f);

void fix_height(st_node_branch *vertex);

void print_tree(st_tree tree, bool is_balanced);

static void prepare_data_for_print(const struct node_branch *vertex, char *buffer);

void print_hash_table(st_hash_table table);

int maxDepth(st_node_branch *node);

void fix_avl_tree(st_node_branch *tree);

#endif
