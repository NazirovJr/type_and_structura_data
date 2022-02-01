//
// Created by nazirov on 13.11.2021.
//

#ifndef LAB5_PRINT_H
#define LAB5_PRINT_H
#include <stdio.h>
#include <math.h>
#include "utils.h"
void print_timing_result(int first_finish, int ft_cur, double f_average, int sc_cur, double s_average,
                         double time_ft, double time_sc);

void print__que_info(double time_line_res, double un_time, int f_arrived, int first_finish,
                     size_t s_arrived, int second_finish, int sc_thrown, double time_ft, double time_sc, double iteration);

void print_theory(double tstop, double t_all, int in1, int in2, int t1_1, int t1_2,
                  int t2_1, int t2_2, int t3_1, int t3_2, int t4_1, int t4_2);

#endif //LAB5_PRINT_H
