//
// Created by nazirov on 04.12.2021.
//

#ifndef LAB6_STRUCT_H
#define LAB6_STRUCT_H


typedef struct node_branch {
    char *key;
    int height;
    struct node_branch *left;
    struct node_branch *right;
} st_node_branch;

typedef struct node_tree
{
    st_node_branch *root;
    int size;
    int total_compare;
} st_tree;


typedef struct node {
    char *string;
    struct node *next;
} node_el;

typedef struct hash_element {
    node_el *ptr;
    int total_compare;
    int size;
} st_hash_table;

#endif //LAB6_STRUCT_H
