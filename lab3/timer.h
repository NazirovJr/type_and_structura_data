#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include "sum_matrix.h"


#define I_STEP 100
#include <stdint.h>
#include <inttypes.h>

uint64_t tick(void)
{
    uint32_t high, low;
    __asm__ __volatile__ (
    "rdtsc\n"
    "movl %%edx, %0\n"
    "movl %%eax, %1\n"
    : "=r" (high), "=r" (low)
    :: "%rax", "%rbx", "%rcx", "%rdx"
    );

    uint64_t ticks = ((uint64_t)high << 32) | low;

    return ticks;
}

void generate_data( int64_t total_ticks, size_t size, int64_t ft_time)
{
    printf("| %14ld | %6zu | %13" PRId64 " |\n", total_ticks, size, ft_time);
    printf("|----------------|--------|---------------|\n");
}


void print_time_table(char *str)
{
    printf("|----------------|--------|---------------|\n");
    printf("| %14s | %6s | %13s |\n", "TICK", "SIZE", str);
    printf("|----------------|--------|---------------|\n");
}


void measurer_sm_matrix_sum(sm_matrix *ft_matrix, sm_matrix *sc_matrix, sm_matrix *res_matrix, dolled_matrix *ft_dolled_matrix, dolled_matrix *sc_dolled_matrix, dolled_matrix *res_dolled_matrix)
{
    struct timeval tv_start, tv_stop;
    int64_t start, end;
    int64_t time_m;
    print_time_table("Simple Matrix");
    copy_sm_matrix_to_dolled(ft_matrix, ft_dolled_matrix);
    copy_sm_matrix_to_dolled(sc_matrix, sc_dolled_matrix);
    start = tick();
    gettimeofday(&tv_start, NULL);
    sum_normal_matrix(ft_matrix, sc_matrix, res_matrix);
    gettimeofday(&tv_stop, NULL);
    end = tick();
    time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    generate_data(end - start,   sizeof(int) * res_matrix->row * res_matrix->column, time_m);

    printf("\n\n");
    print_time_table("Dolled Matrix");
    start = tick();
    gettimeofday(&tv_start, NULL);
    sum_dolled_matrix(res_dolled_matrix, ft_dolled_matrix, sc_dolled_matrix);
    gettimeofday(&tv_stop, NULL);
    end = tick();
    time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    generate_data(end - start,  sizeof(int) * (res_dolled_matrix->PA - res_dolled_matrix->A) + sizeof(int) * (res_dolled_matrix->IPA - res_dolled_matrix->AI) + sizeof(int) * (res_dolled_matrix->JA.p_index - res_dolled_matrix->JA.index) , time_m);

}

#endif

