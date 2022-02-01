//
// Created by nazirov on 09.11.2021.
//

#ifndef LAB5_QUE_STRUCT_H
#define LAB5_QUE_STRUCT_H
#include <stdio.h>
#include "utils.h"

typedef struct node_el {
    double data;
    struct node_el *next;
} node;

typedef struct {
    node *head, *tail;
    size_t size;
} st_list_que;

typedef struct {
    double *arr;
    size_t size;
} st_arr_que;

#endif //LAB5_QUE_STRUCT_H
