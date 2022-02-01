//
// Created by nazirov on 13.11.2021.
//

#include "../inc/print.h"

void print_timing_result(int first_finish, int ft_cur, double f_average, int sc_cur, double s_average,
                         double time_ft, double time_sc) {
    printf("\n--------------------------------------------------\n");
    printf("\nFor: %d\n", first_finish);
    printf("--------------------------------------------------\n");
    printf("Currently length first queue: %d\n", ft_cur);
    printf("Average length first queue: %2.1lf\n", f_average);
    printf("Currently length second queue: %d\n", sc_cur);
    printf("Average length second queue: %2.1lf\n", s_average);
    printf("Average time first type queue: %2.1f\n", time_ft);
    printf("Average time second type queue: %2.1f\n", time_sc);
}

void print__que_info(double time_line_res, double un_time, int f_arrived, int first_finish,
                     size_t s_arrived, int second_finish, int sc_thrown, double time_ft, double time_sc,
                     double iteration) {
    printf("\n--------------------------------------------------\n");
    printf("Result\n");
    printf("--------------------------------------------------\n");
    printf(" --- 1 --> Time in work: %2.1lf\n", time_line_res);
    printf(" --- 2 --> Time not work: %2.1lf\n", un_time);
    printf(" --- 3 --> Amount T1 elements(all) go: %d\n", f_arrived);
    printf(" --- 4 --> Amount T1 elements(only) go: %d\n", first_finish);
    printf(" --- 5 --> Amount T2 elements(all) go: %d\n", s_arrived);
    printf(" --- 6 --> Amount T2 elements(only) go: %d\n", second_finish);
    printf(" --- 7 --> Amount T2 elements(go out): %d\n", sc_thrown);
    printf(" --- 8 --> Average time first type queue: %2.1f\n", time_ft);
    printf(" --- 9 --> Average time second type queue: %2.1f\n", time_sc);
    printf(" --- 10 --> Time Apparatus Work: %lf\n", time_line_res - un_time);
    printf(" --- 11 --> Percent: %lf%%", iteration);
}


void print_theory(double tstop, double t_all, int in1, int in2, int t1_1, int t1_2,
              int t2_1, int t2_2, int t3_1, int t3_2, int t4_1, int t4_2)
{

    double t_alln, tstopn, tmin;
    double in1n = MAX_SIZE_OF_QUE;
    double in2n;

    double time1 = ((double)(t1_2 + t1_1))/2 * MAX_SIZE_OF_QUE;
    double time2 = ((double)(t3_2 + t3_1))/2 * MAX_SIZE_OF_QUE;
    if (time1 > time2)
    {
        t_alln = time1;
        tmin = time2;
    }
    else
    {
        t_alln = time2;
        tmin = time1;
    }
    in1n = t_alln / ((double)(t1_2 + t1_1)/2);
    in2n =  t_alln / ((double)(t2_2 + t2_1)/2);
    tstopn = t_alln - tmin - (double)(t4_2 + t4_1)/2 * in2n;
    tstopn *= -1;
    double pr1 = fabs(t_alln - t_all) / t_alln * 100;
    double pr2 = fabs(in1n - in1) / in1n * 100;
    double pr3 = fabs(in2n - in2) / in2n * 100;

    double max;
    if( pr1 > pr2 && pr1 > pr3)
        max = pr1;
    else if (pr2 > pr1 && pr2 > pr3)
    {
        max = pr2;
    }
    else
    {
        max = pr3;
    }
    printf("\nTheory results: \n");
    printf("All time of modulation = %lf\n", t_alln);
    printf("Wait time = %lf\n", tstopn);
    printf("in 1 type  = %lf\n", in1n);
    printf("in 2 type  = %lf \n", in2n);
//    printf("percent is %f\n", max);
}