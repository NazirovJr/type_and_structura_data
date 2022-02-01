#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include "list_stack_operation.h"
#include "stack_struct.h"
#define I_STEP 10
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

void generator_arr(stack_array *stack, size_t size)
{
    while (stack->top_size <= size)
        arr_el_push(stack, rand() % MAX_RANDOM_VALUE,  rand() % MAX_RANDOM_ZNAK_VALUE);
}

void generator_list(stack_list **stack, size_t size)
{
    for (int i = 0; i <= size; ++i)
        list_el_push(stack, rand() % MAX_RANDOM_VALUE, rand() % MAX_RANDOM_ZNAK_VALUE);
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


void measure_generate_element(stack_array *stack_arr, stack_list **stack_list)
{
    int64_t start, end;
    print_time_table("Array Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP)
    {
        start = tick();
        generator_arr(stack_arr, i);
        end = tick();
        generate_data(end - start,   sizeof(int) * (MAX_SIZE_OF_STACK / I_STEP) * 2, i);
    }
    printf("\n\n");
    print_time_table("List Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP)
    {
        start = tick();
        generator_list(stack_list, i);
        end = tick();
        generate_data(end - start,   sizeof(int) * 2 * i + sizeof(node) * i, i);
    }
}


void measure_pop_element(stack_array *stack_arr, stack_list **stack_list)
{
    int64_t start, end;
    print_time_table("Array Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP)
    {
        generator_arr(stack_arr, i);
        start = tick();
        clean_arr_stack(stack_arr);
        end = tick();
        generate_data(end - start,   sizeof(int) * 2 * (MAX_SIZE_OF_STACK / I_STEP), i);
    }
    printf("\n\n");
    print_time_table("List Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP)
    {
        generator_list(stack_list, i);
        start = tick();
        clean_list_stack(stack_list);
        end = tick();
        generate_data(end - start,   sizeof(int) * 2 * i + sizeof(node) * i, i);
    }
}

void measure_operation_element(stack_array *stack_arr, stack_list **stack_list) {
    int64_t start, end;
    print_time_table("Array Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP) {
        generator_arr(stack_arr, i);
        start = tick();
        stack_arr_el_operation(stack_arr);
        end = tick();
        generate_data(end - start, sizeof(int) * 2 * (MAX_SIZE_OF_STACK / I_STEP), i);
    }
    printf("\n\n");
    print_time_table("List Stack");
    for (int i = I_STEP; i < MAX_SIZE_OF_STACK; i *= I_STEP) {
        generator_list(stack_list, i);
        start = tick();
        stack_list_el_operation(stack_list);
        end = tick();
        generate_data(end - start, sizeof(int) * 2 * i + sizeof(node) * i, i);
    }
}
#endif

