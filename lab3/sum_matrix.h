//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_SUM_MATRIX_H
#define LAB3_SUM_MATRIX_H


#include "struct.h"
#include <stdlib.h>
int getInt(const dolled_matrix *res_matrix, const dolled_matrix *ft_matrix, const dolled_matrix *sc_matrix, int size,
           int check, int i);

void
sc_part_sum_op(const dolled_matrix *res_matrix, const dolled_matrix *ft_matrix, const dolled_matrix *sc_matrix, int i,
               int *size, int *check);

void sum_normal_matrix(sm_matrix *ft_matrix, sm_matrix *sc_matrix, sm_matrix *res_matrix)
{
    for (int i = 0; i < ft_matrix->row; ++i)
        for (int j = 0; j < ft_matrix->column; ++j)
            res_matrix->matrix[i][j] = ft_matrix->matrix[i][j] + sc_matrix->matrix[i][j];

}



void sum_dolled_matrix(dolled_matrix *res_matrix, dolled_matrix *ft_matrix, dolled_matrix *sc_matrix)
{
    res_matrix->A = (int *)malloc((ft_matrix->amount_of_ne + sc_matrix->amount_of_ne) * sizeof(int));
    res_matrix->AI = (int *)malloc((ft_matrix->amount_of_ne + sc_matrix->amount_of_ne) * sizeof(int));
    res_matrix->JA.index = (int *)malloc((ft_matrix->column + 1) * sizeof(int));

    res_matrix->PA = res_matrix->A;
    res_matrix->IPA = res_matrix->AI;
    res_matrix->JA.p_index = res_matrix->JA.index;

    int size = 0, js_size = 0, check = 0;
    *(res_matrix->JA.index + js_size) = 0;
    js_size++;
    for(int i = 1; i < ft_matrix->JA.p_index - ft_matrix->JA.index; i++)
    {
        size = getInt(res_matrix, ft_matrix, sc_matrix, size, check, i);
        sc_part_sum_op(res_matrix, ft_matrix, sc_matrix, i, &size, &check);
        *(res_matrix->JA.index + js_size) = size;
        js_size++;
    }

    res_matrix->PA = res_matrix->A + size;
    res_matrix->IPA = res_matrix->AI + size;
    res_matrix->JA.p_index = res_matrix->JA.index + js_size;

}

void sc_part_sum_op(const dolled_matrix *res_matrix, const dolled_matrix *ft_matrix, const dolled_matrix *sc_matrix, int i,
               int *size, int *check) {
    for(int k = *(sc_matrix->JA.index + i - 1); k < *(sc_matrix->JA.index + i); k++)
    {
        (*check) = 0;
        for(int j = *(ft_matrix->JA.index + i - 1); j < *(ft_matrix->JA.index + i); j++)
        {
            if (*(ft_matrix->AI + j) == *(sc_matrix->AI + k))
                (*check) = 1;
        }
        if ((*check) == 0)
        {
            *(res_matrix->A + (*size)) = *(sc_matrix->A + k);
            *(res_matrix->AI + (*size)) = *(sc_matrix->AI + k);
            (*size)++;
        }
    }
}

int getInt(const dolled_matrix *res_matrix, const dolled_matrix *ft_matrix, const dolled_matrix *sc_matrix, int size,
           int check, int i) {
    for(int j = *(ft_matrix->JA.index + i - 1); j < *(ft_matrix->JA.index + i); j++)
    {
        check = 0;
        for(int k = *(sc_matrix->JA.index + i - 1); k < *(sc_matrix->JA.index + i); k++)
        {
            if (*(ft_matrix->AI + j) == *(sc_matrix->AI + k))
            {
                *(res_matrix->A + size) = *(ft_matrix->A + j) + *(sc_matrix->A + k);
                *(res_matrix->AI + size) = *(ft_matrix->AI + j);
                size++;
                check = 1;
            }
        }
        if (check == 0)
        {
            *(res_matrix->A + size) = *(ft_matrix->A + j);
            *(res_matrix->AI + size) = *(ft_matrix->AI + j);
            size++;
        }
    }
    return size;
}


#endif //LAB3_SUM_MATRIX_H
