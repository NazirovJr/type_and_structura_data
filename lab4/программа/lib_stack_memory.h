//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_LIB_STACK_MEMORY_H
#define LAB4_LIB_STACK_MEMORY_H
#include <stdlib.h>
#include "stack_struct.h"
#include "limitation.h"
#include "errors.h"
#define AMOUNT_OF_ELEMENT 2
#define START_FAA_SIZE 10

void list_stack_free(stack_list **stack)
{
    node *temp;
    for  (; (*stack)->ptr; (*stack)->ptr = temp) {
        temp = (*stack)->ptr->prev;
        free((*stack)->ptr);
    }

}
void free_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; ++i)
        free(matrix[i]);
    free(matrix);
    matrix = NULL;
}

int **allocate_matrix_memory(int row, int column)
{
    int **matrix = calloc(row, sizeof(int *));
    if (matrix)
    {
        for (int i = 0; i < row; ++i)
        {
            matrix[i] = malloc(column * sizeof(int ));
            if (!matrix[i])
            {
                free_matrix(matrix, row);
                break;
            }
        }
    }
    return matrix;
}

void array_stack_free(stack_array *stack)
{
    free_matrix(stack->arr_stack, stack->top_size);
    stack->top_size = 0;
}


int stack_arr_init(stack_array *stack)
{
    stack->size = MAX_SIZE_OF_STACK;
    stack->top_size = 0;
    stack->arr_stack = allocate_matrix_memory(stack->size, AMOUNT_OF_ELEMENT);
    if (!stack->arr_stack)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}


int arr_free_area_init(stack_array *stack)
{
    stack->size = MAX_SIZE_OF_STACK;
    stack->top_size = 0;
    stack->arr_stack = allocate_matrix_memory(stack->size, START_FAA_SIZE);
    if (!stack->arr_stack)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

node *stack_list_el_init(int num, int znak)
{
    node *element = malloc(sizeof(node));
    if (element) {
        element->number = num;
        element->obelus = znak;
        element->prev = NULL;
    }
    return element;
}

#endif //LAB4_LIB_STACK_MEMORY_H
