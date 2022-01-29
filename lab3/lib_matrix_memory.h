//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_LIB_MATRIX_MEMORY_H
#define LAB3_LIB_MATRIX_MEMORY_H
#include "struct.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

int allocate_matrix(sm_matrix *const matrix)
{
    matrix->matrix = malloc(matrix->row * sizeof(int *));

    if (matrix->matrix == NULL)
    {
        return MEMORY_ERROR;
    }

    for (unsigned i = 0; i < matrix->row; i++)
    {
        *(matrix->matrix + i) = malloc(matrix->column * sizeof(int));

        if (*(matrix->matrix + i) == NULL)
        {
            return MEMORY_ERROR;
        }
    }

    return EXIT_SUCCESS;
}

void free_sm_matrix_memory(sm_matrix *const matrix)
{
    for (unsigned i = 0; i < matrix->row; i++)
    {
        free(matrix->matrix[i]);
        matrix->matrix[i] = NULL;
    }
    free(matrix->matrix);
    matrix->matrix = NULL;
}

void free_dolled_matrix(dolled_matrix *matrix)
{
    free(matrix->A);
    free(matrix->AI);
    free(matrix->JA.index);
    matrix->A = NULL;
    matrix->AI = NULL;
    matrix->JA.index = NULL;
}

#endif //LAB3_LIB_MATRIX_MEMORY_H
