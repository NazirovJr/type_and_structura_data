//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_STRUCT_H
#define LAB3_STRUCT_H
#include <stdio.h>

typedef struct child {
    int *index;
    int *p_index;
} child_el;


typedef struct {
    size_t row;
    size_t column;
    size_t amount_of_ne;

    int *A;
    int *AI;
    int *PA;
    int *IPA;
    struct child JA;
} dolled_matrix;

typedef struct {
    int **matrix;
    size_t row;
    size_t column;
} sm_matrix;

#endif //LAB3_STRUCT_H
