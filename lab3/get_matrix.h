//
// Created by nazirov on 14.10.2021.
//

#ifndef LAB3_GET_MATRIX_H
#define LAB3_GET_MATRIX_H
#include <stdio.h>
#include "struct.h"
#include "limitation.h"
#include "lib_matrix_memory.h"

int get_matrix_param(dolled_matrix *matrix)
{
    printf("\nEnter matrix size of row and column: ");
    if ((scanf("%zd", &matrix->row) != 1) || (matrix->row > MAX_SIZE_ROW || matrix->row <= MIN_SIZE))
    {
        printf("\nError! The size of array is small or big!");
        return CONSOLE_ERROR;
    }
    if ((scanf("%zd", &matrix->column) != 1) || (matrix->column > MAX_SIZE_COLUMN || matrix->column < 0))
    {
        printf("\nError! The size of array is small or big!");
        return CONSOLE_ERROR;
    }
    printf("\nEnter the amount of not null number: ");
    if ((scanf("%zd", &matrix->amount_of_ne) != 1) || (matrix->amount_of_ne > matrix->row * matrix->column))
    {
        printf("\nError! Incorrect input amount of not null number!");
        return CONSOLE_ERROR;
    }
    return EXIT_SUCCESS;
}

int get_value(sm_matrix *matrix, const int amount_of_ne)
{
    int num = 0, exit = EXIT_SUCCESS;
    for (int k = 0; k < matrix->row; ++k) {
        for (int i = 0; i < matrix->column; ++i) {
            matrix->matrix[k][i] = 0;
        }
    }

    printf("\nEnter the not null elements of matrix:\n");
    for (int i = 0; i < amount_of_ne; ++i)
    {
        int r_index, c_index;
        printf("\nEnter %d not null element: ", i + 1);
        if (scanf("%d", &num) != 1 || num == 0 || num > MAX_INT)
        {
            printf("Error! Please enter correct data!");
            exit = CONSOLE_ERROR;
            break;
        }
        printf("\nEnter the index row of element (indexation starting with zero) :");
        if (scanf("%d", &r_index) != 1 || r_index > matrix->row || r_index < 0)
        {
            printf("Error! Incorrect index of row!");
            exit = CONSOLE_ERROR;
            break;
        }
        printf("\nEnter the index column of element (indexation starting with zero) :");
        if (scanf("%d", &c_index) != 1 || c_index > matrix->column || c_index < 0)
        {
            printf("Error! Incorrect index of column!");
            exit = CONSOLE_ERROR;
            break;
        }
        if (matrix->matrix[r_index][c_index] == 0)
            matrix->matrix[r_index][c_index] = num;
        else
        {
            exit = CONSOLE_ERROR;
            printf("\nSorry this row and column was used please enter again correct value!\n");
            i--;
        }
    }
    return exit;
}


#endif //LAB3_GET_MATRIX_H
