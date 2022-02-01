#include <stdio.h>
#include <stdlib.h>
#include "stack_struct.h"
#include "list_stack_operation.h"
#include "lib_stack_memory.h"
#include "menu.h"
#include "fill_stack.h"
#include "print_struct.h"
#include "timer.h"
#include "delete_matrix.h"

int process(stack_array *arr_stack, stack_list **list_stack, stack_array *, int *, int choice);

int main(void ) {
    int rc = EXIT_SUCCESS, choice = 1, len_list_stack = 0;
    stack_array arr_stack, arr_free_area;
    stack_list list_stack, *p_list_stack;
    p_list_stack = &list_stack;
    p_list_stack->ptr = NULL;
    rc = stack_arr_init(&arr_stack);
    if (rc == EXIT_SUCCESS)
    {
        rc = arr_free_area_init(&arr_free_area);
        while (choice && rc == EXIT_SUCCESS)
        {
            menu(&choice);
            rc = process(&arr_stack, &p_list_stack, &arr_free_area, &len_list_stack, choice);
        }
    }

    array_stack_free(&arr_free_area);
    array_stack_free(&arr_stack);
    list_stack_free(&p_list_stack);
    printf("Good bye, World!\n");
    return rc;
}

int process(stack_array *arr_stack, stack_list **list_stack, stack_array *arr_free_area, int *len_list_stack, int choice)
{
    int rc = EXIT_SUCCESS;
    if (!arr_stack->top_size && choice > 1 && choice < 6 && choice != 3 || (*list_stack)->ptr == NULL && choice > 6 && choice < 11 && choice != 8) {
        printf("Empty stack!!!");
        return rc;
    }

    switch (choice) {
        case 1:
        {
            rc = fill_arr_stack(arr_stack);
            if (rc == STACK_OVERFLOW)
            {
                printf("Stack Overflow!!!");
                rc = EXIT_SUCCESS;
            }
            break;
        }
        case 2:
        {
            rc = remove_arr_stack(arr_stack, arr_free_area);
            break;
        }
        case 3:
        {
            fill_random_arr_stack(arr_stack);
            break;
        }
        case 4:
        {
            printf("Result equal to : %d", stack_arr_el_operation(arr_stack));
            break;
        }
        case 5:
        {
            print_array_stack(arr_stack);
            break;
        }
        case 6:
        {
            rc = fill_list_stack(list_stack);
            if (rc == STACK_OVERFLOW)
            {
                printf("Stack Overflow!!!");
                rc = EXIT_SUCCESS;
            }
            break;
        }
        case 7:
        {
            rc = remove_list_stack(list_stack, arr_free_area);
            break;
        }
        case 8:
        {
            rc = fill_random_list_stack(list_stack);
            break;
        }
        case 9:
        {
            printf("Result equal to : %d", stack_list_el_operation(list_stack));
            break;
        }
        case 10:
        {
            print_list_stack(*list_stack);
            break;
        }
        case 11:
        {
            clean_list_stack(list_stack);
            clean_arr_stack(arr_stack);
            printf("\n\n\t\t-- Measurement of pushing element from stack --\n\n");
            measure_generate_element(arr_stack, list_stack);
            clean_list_stack(list_stack);
            clean_arr_stack(arr_stack);
            printf("\n\n\t\t-- Measurement of removing element from stack --\n\n");
            measure_pop_element(arr_stack, list_stack);
            clean_list_stack(list_stack);
            clean_arr_stack(arr_stack);
            printf("\n\n\t\t-- Measurement of operation with element of stack --\n\n");
            measure_operation_element(arr_stack, list_stack);
            break;
        }
        case 12:
        {
            if (!arr_stack->top_size)
                printf("The array of free address is empty!!!");
            else
            {
                printf("The address of deleted element: ");
                for (int i = 0; i < arr_free_area->top_size; ++i)
                    printf("\n%p", arr_free_area->arr_stack[i]);
            }
            break;
        }
        case 0:
            break;
        default:
            break;

    }
    return rc;
}