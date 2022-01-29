//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_PRINT_MATRIX_H
#define LAB3_PRINT_MATRIX_H
#include "struct.h"
void print_matrix(const sm_matrix *matrix)
{
    for (int i = 0; i < matrix->row; ++i) {
        for (int j = 0; j < matrix->column; ++j) {
            printf("%d\t", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_sparse_format(dolled_matrix matrix)
{
    printf(" A = [ ");

    for (; matrix.A < matrix.PA; matrix.A++)
        printf("%d ", *matrix.A);

    printf("]\n");
    printf("IA = [ ");

    for (; matrix.AI < matrix.IPA; matrix.AI++)
        printf("%d ", *matrix.AI);

    printf("]\n");
    printf("JA = [ ");

    for (; matrix.JA.index < matrix.JA.p_index; matrix.JA.index++)
        printf("%d ", *matrix.JA.index);

    printf("]\n");
}

#endif //LAB3_PRINT_MATRIX_H
