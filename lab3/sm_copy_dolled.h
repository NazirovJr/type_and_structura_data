//
// Created by nazirov on 15.10.2021.
//

#ifndef LAB3_SM_COPY_DOLLED_C
#define LAB3_SM_COPY_DOLLED_C
#include "struct.h"
#include <stdlib.h>

void copy_sm_matrix_to_dolled(sm_matrix *matrix, dolled_matrix *doll_matrix)
{
    doll_matrix->A = (int*)malloc(doll_matrix->amount_of_ne * sizeof(int));
    doll_matrix->AI = (int*)malloc(doll_matrix->amount_of_ne * sizeof(int));
    doll_matrix->JA.index  = (int *)malloc((doll_matrix->column + 1) * sizeof(int));
    doll_matrix->PA = doll_matrix->A;
    doll_matrix->IPA = doll_matrix->AI;
    doll_matrix->JA.p_index = doll_matrix->JA.index;

    int a_ind = 0, ja_ind = 0, zero_c = 0;
    *(doll_matrix->JA.index + ja_ind) = 0;
    ja_ind++;
    for (int i = 0; i < doll_matrix->column; i++)
    {
        for (int j = 0; j < doll_matrix->row; j++)
        {
            if (matrix->matrix[j][i] != 0)
            {
                *(doll_matrix->A + a_ind) = matrix->matrix[j][i];
                *(doll_matrix->AI + a_ind) = j;
                a_ind++;
                zero_c ++;
            }
        }
        *(doll_matrix->JA.index + ja_ind) = a_ind;
        zero_c = 0;
        ja_ind++;
    }

    doll_matrix->PA = doll_matrix->A + a_ind;
    doll_matrix->IPA = doll_matrix->AI + a_ind;
    doll_matrix->JA.p_index = doll_matrix->JA.index + ja_ind;

}

#endif //LAB3_SM_COPY_DOLLED_C
