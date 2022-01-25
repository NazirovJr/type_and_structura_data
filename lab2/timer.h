#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include "st_sort.h"


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

void generate_data( int64_t total_ticks, size_t size, int amount, int64_t ft_time)
{
    printf("| %14ld | %6zu | %6" PRId64 " |\n", total_ticks, size * amount, ft_time);
    printf("|----------------|--------|--------|\n");
}


void print_time_table(char *str)
{
    printf("|----------------|--------|--------|\n");
    printf("| %14s | %6s | %6s |\n", "TICK", "SIZE", str);
    printf("|----------------|--------|--------|\n");
}


void measurer_time_table_sort(st_travel *travel, st_key *key_data, int st_len)
{
    struct timeval tv_start, tv_stop;
    int64_t start, end, end1, start1;
    int64_t time_m, time_q;
    printf("\nСравнение Selection sort и qsort для сортировки ключей.\n");
    print_time_table("S_SORT");
    start = tick();
    gettimeofday(&tv_start, NULL);
    st_selection_sort_by_key(key_data, st_len);
    gettimeofday(&tv_stop, NULL);
    end = tick();
    time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    generate_data(end - start, sizeof(*key_data), st_len, time_m);

    st_initialize_key(key_data, travel, st_len);
    printf("\n\n");
    print_time_table("QSORT");
    start1 = tick();
    gettimeofday(&tv_start, NULL);
    qsort(key_data, st_len, sizeof(*key_data), comparator_keys);
    gettimeofday(&tv_stop, NULL);
    end1 = tick();


    time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    generate_data(end1 - start1, sizeof(*key_data), st_len, time_q);

}

void time_table_sort(st_travel *travel, st_key *key_data, int st_len) {
    struct timeval tv_start, tv_stop, tv_start1, tv_stop1;
    int64_t start, end, end1, start1;
    int64_t time_m, time_q;
    printf("\nСравнение сортировки таблицы Selection sort и QSORT\n");
    print_time_table("S_SORT");

    start = tick();
    gettimeofday(&tv_start1, NULL);
    st_selection_sort(travel, key_data, st_len);
    gettimeofday(&tv_stop1, NULL);
    end = tick();
    time_m = (tv_stop1.tv_sec - tv_start1.tv_sec) * 1000000LL + (tv_stop1.tv_usec - tv_start1.tv_usec);
    generate_data(end - start, sizeof(*travel), st_len, time_m);
    upload_from_file(travel, &st_len);
    printf("\n\n");
    print_time_table("QSORT");
    start1 = tick();
    gettimeofday(&tv_start, NULL);
    qsort(travel, st_len, sizeof(*travel), comparator_table);
    gettimeofday(&tv_stop, NULL);
    end1 = tick();
    time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    generate_data(end1 - start1, sizeof(*travel), st_len, time_q);
}

#endif

