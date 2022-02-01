//
// Created by nazirov on 26.10.2021.
//

#ifndef LAB4_DELETE_MATRIX_H
#define LAB4_DELETE_MATRIX_H
#include "stack_struct.h"
#include "list_stack_operation.h"
#include "fill_stack.h"

int remove_arr_stack(stack_array *stack, stack_array *arr_free_area) {
    int size = 0, rc = EXIT_SUCCESS;
    printf("Enter the amount of removing elements: ");
    while (scanf("%d", &size) != 1 || size < 1 || size > stack->top_size) {
        printf("Enter correctly the amount of removing elements: ");
        clean_buffer();
    }
    int *p;
    printf("\nThe addresses of deleting element:");
    for (int i = 0; i < size && rc == EXIT_SUCCESS; ++i) {
        p = arr_el_pop(stack);
        rc = arr_el_push_free_area(arr_free_area, p);
        if (rc == EXIT_SUCCESS)
            printf("\n%p", p);
    }
    return rc;
}

int remove_list_stack(stack_list **stack, stack_array *arr_free_area) {
    int size = 0, len = get_amount_of_list_el(*stack), rc = EXIT_SUCCESS;
    printf("Enter the amount of removing elements: ");
    while (scanf("%d", &size) != 1 || size < 1 || size > len) {
        printf("Enter correctly the amount of removing elements: ");
        clean_buffer();
    }
    int *p;
    printf("\nThe addresses of deleting element:");
    for (int i = 0; i < size && rc == EXIT_SUCCESS; ++i) {
        p = list_el_pop(stack);
        rc = arr_el_push_free_area(arr_free_area, p);
        if (rc == EXIT_SUCCESS)
            printf("\n%p", p);
    }
    return rc;
}


#endif //LAB4_DELETE_MATRIX_H
