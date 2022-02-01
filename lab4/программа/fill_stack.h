//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_FILL_STACK_H
#define LAB4_FILL_STACK_H

#include "stack_struct.h"
#include "lib_stack_memory.h"
#include "list_stack_operation.h"
#include <stdlib.h>
#include <stdio.h>

#define LINE_SIZE 100

void fill_random_arr_stack(stack_array *stack) {
    int size;
    printf("Please enter amount of random element (> 0 and <= 10000): ");
    while (scanf("%d", &size) != 1 || size >= MAX_SIZE_OF_STACK || size < 1) {
        printf("Please enter amount of random element correctly (> 0 and <= 10000): ");
        clean_buffer();
    }

    while (stack->top_size < size)
        arr_el_push(stack, rand() % MAX_RANDOM_VALUE, rand() % MAX_RANDOM_ZNAK_VALUE);
}

int fill_random_list_stack(stack_list **stack) {
    int size;
    printf("Please enter amount of random element (> 0 and <= 10000): ");
    while (scanf("%d", &size) != 1 || size >= MAX_SIZE_OF_STACK || size < 1) {
        printf("Please enter amount of random element correctly (> 0 and <= 10000): ");
        clean_buffer();
    }

    for (int i = 0; i < size; ++i)
        list_el_push(stack, rand() % MAX_RANDOM_VALUE, rand() % MAX_RANDOM_ZNAK_VALUE);

    return EXIT_SUCCESS;
}

int fill_arr_stack(stack_array *stack) {
    int size = 0, rc = EXIT_SUCCESS;
    char buff[LINE_SIZE];
    printf("Enter the expression: ");
    scanf("%s", buff);
    rc = ck_entered_data(stack, buff);
    return rc;
}

int get_amount_of_list_el(stack_list *stack) {
    int counter = 0;
    node *head;
    stack_list stack_list, *p_stack;
    p_stack = &stack_list;
    if (stack->ptr == NULL)
        return counter;

    p_stack->ptr = copy_list_stack(stack->ptr);
    for (; p_stack->ptr->prev; p_stack->ptr = head) {
        head = p_stack->ptr->prev;
        counter++;
        free(p_stack->ptr);
    }
    counter++;
    free(p_stack->ptr);
    return counter;
}



int fill_list_stack(stack_list **stack) {
    int size = 0, rc = EXIT_SUCCESS;

    char buff[LINE_SIZE];
    printf("Enter the expression: ");
    scanf("%s", buff);
    if (ck_list_entered_data(stack, buff) != EXIT_SUCCESS)
        rc = INVALID_DATA;

    return rc;
}

#endif //LAB4_FILL_STACK_H
