#include <stdio.h>
#include "struct.h"
#include "get_matrix.h"
#include "print_matrix.h"
#include "init_matrix.h"
#include "sm_copy_dolled.h"
#include "sum_matrix.h"
#include "menu.h"
#include "timer.h"

int process_init_sm_matrix(sm_matrix *ft_norm_matrix, sm_matrix *sc_norm_matrix, sm_matrix *res_norm_matrix, int row,
                           int column);

int main(void) {
    int rc = EXIT_SUCCESS, choice;
    sm_matrix ft_norm_matrix, sc_norm_matrix, res_norm_matrix;
    dolled_matrix ft_doll_matrix, sc_doll_matrix, res_dol_matrix;
    rc = menu(&choice);
    if (rc == EXIT_SUCCESS)
        rc = get_matrix_param(&ft_doll_matrix);

    if (rc == EXIT_SUCCESS) {
        rc = get_matrix_param(&sc_doll_matrix);
        if (rc == EXIT_SUCCESS) {
            if (sc_doll_matrix.row != ft_doll_matrix.row ||
                ft_doll_matrix.column != sc_doll_matrix.column) { rc = NOT_MATCH; }
        }
    }

    if (rc == EXIT_SUCCESS) {
        rc = process_init_sm_matrix(&ft_norm_matrix, &sc_norm_matrix, &res_norm_matrix, ft_doll_matrix.row,
                                    ft_doll_matrix.column);
    }


    if (rc == EXIT_SUCCESS) {

        switch (choice) {
            case 1:
            {
                rc = get_value(&ft_norm_matrix, ft_doll_matrix.amount_of_ne);
                if (rc == EXIT_SUCCESS)
                    rc = get_value(&sc_norm_matrix, sc_doll_matrix.amount_of_ne);
                break;
            }
            case 2:
            {
                matrix_generate(&ft_norm_matrix, ft_doll_matrix.amount_of_ne);
                matrix_generate(&sc_norm_matrix, sc_doll_matrix.amount_of_ne);
                break;
            }
            case 3:
            {
                matrix_generate(&ft_norm_matrix, ft_doll_matrix.amount_of_ne);
                matrix_generate(&sc_norm_matrix, sc_doll_matrix.amount_of_ne);
                measurer_sm_matrix_sum(&ft_norm_matrix, &sc_norm_matrix, &res_norm_matrix, &ft_doll_matrix, &sc_doll_matrix, &res_dol_matrix);
                break;
            }
            default:
                break;
        }
      if (rc == EXIT_SUCCESS && choice != 3)
      {

          copy_sm_matrix_to_dolled(&ft_norm_matrix, &ft_doll_matrix);
          copy_sm_matrix_to_dolled(&sc_norm_matrix, &sc_doll_matrix);
          sum_normal_matrix(&ft_norm_matrix, &sc_norm_matrix, &res_norm_matrix);
          sum_dolled_matrix(&res_dol_matrix, &ft_doll_matrix, &sc_doll_matrix);
          if (ft_norm_matrix.row < 10 && ft_norm_matrix.column < 10)
          {
              printf("First norm matrix:\n");
              print_matrix(&ft_norm_matrix);
              printf("\nSecond norm matrix:\n");
              print_matrix(&sc_norm_matrix);

              printf("\n\n Sum result of norm matrix:\n");
              print_matrix(&res_norm_matrix);
          }
          printf("\n\nFirst dolled matrix:\n");
          print_matrix_sparse_format(ft_doll_matrix);
          printf("\nSecond dolled matrix:\n");
          print_matrix_sparse_format(sc_doll_matrix);
          printf("\nSum result of dolled matrix:\n");
          print_matrix_sparse_format(res_dol_matrix);

      }
    }
    //free_sm_matrix_memory(&ft_norm_matrix);
    //free_sm_matrix_memory(&sc_norm_matrix);
    //free_sm_matrix_memory(&res_norm_matrix);
    //free_dolled_matrix(&ft_doll_matrix);
    //free_dolled_matrix(&sc_doll_matrix);
    //free_dolled_matrix(&res_dol_matrix);
    return rc;
}

int process_init_sm_matrix(sm_matrix *ft_norm_matrix, sm_matrix *sc_norm_matrix, sm_matrix *res_norm_matrix, int row,
                           int column) {
    int rc = EXIT_SUCCESS;
    rc = init_sm_matrix(ft_norm_matrix, row, column);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = init_sm_matrix(sc_norm_matrix, row, column);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = init_sm_matrix(res_norm_matrix, row, column);
    return rc;
}