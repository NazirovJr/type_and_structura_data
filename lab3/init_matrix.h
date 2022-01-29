//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_INIT_MATRIX_H
#define LAB3_INIT_MATRIX_H

#include <time.h>
#include <stdbool.h>
#include "struct.h"
#include "lib_matrix_memory.h"

int init_sm_matrix(sm_matrix *matrix, int row, int column)
{
    matrix->row = row;
    matrix->column = column;
    if (allocate_matrix(matrix) != EXIT_SUCCESS)
        return MEMORY_ERROR;
    return EXIT_SUCCESS;
}


int matrix_generate(sm_matrix *matrix, int amount_of_not_zero_el)
{
    for (int j = 0; j < matrix->column; ++j)
        for (int i = 0; i < matrix->row; ++i)
            matrix->matrix[j][i] = 0;

    srand(time(NULL));
    for (int i = 0; i < amount_of_not_zero_el; i++)
    {
        int irand = 0;
        int jrand = 0;
        do
        {
            irand = rand() % matrix->row;
            jrand = rand() % matrix->column;
        } while (matrix->matrix[irand][jrand] != 0);

        matrix->matrix[irand][jrand] = rand() % 100 + 1;
    }

    return EXIT_SUCCESS;
}


#endif //LAB3_INIT_MATRIX_H
