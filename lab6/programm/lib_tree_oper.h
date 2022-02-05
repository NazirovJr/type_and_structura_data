//
// Created by nazirov on 04.12.2021.
//

#ifndef LAB6_LIB_TREE_OPER_H
#define LAB6_LIB_TREE_OPER_H

#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

st_node_branch *remove_in_tree(char *rem, st_node_branch *tree, int *done, int *flag);


st_node_branch *balance(st_node_branch *p_tree, char *key);

int comparator(const void *ft_elem, const void *sc_elem);

st_node_branch *initialize_branch(st_node_branch *p_tree);

st_node_branch *create_node(char *key);

st_node_branch *insert(st_node_branch *node, char *key);

st_node_branch *find_node(st_node_branch *p_tree, char *key);

st_tree *create_tree(void);

st_node_branch *insert_b(st_node_branch *node, char *key);

st_node_branch *remove_node(st_node_branch *p_tree, char *key);

st_node_branch *remove_in_bal_tree(char *rem, st_node_branch *tree, int *done, int *flag);

#endif //LAB6_LIB_TREE_OPER_H
