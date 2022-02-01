//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_PRINT_STRUCT_H
#define LAB4_PRINT_STRUCT_H
#include "stack_struct.h"
#include "list_stack_operation.h"
#include <stdio.h>


char get_znak_symbol(int num)
{
    switch (num) {
        case PLUS:
            return '+';
        case MINUS:
            return '-';
        /*case MULTIPLY:
            return '*';
        case DIVIDE:
            return '/';*/
        default:
            return '+';
    }
}

void print_list_stack(stack_list *p_stack)
{
    node *head;
    head = p_stack->ptr;
    for (; p_stack->ptr->prev; p_stack->ptr = p_stack->ptr->prev)
    {
        printf("\nThe address of element: %p", p_stack->ptr);
        printf("\nThe value of element: %d%c", p_stack->ptr->number, get_znak_symbol(p_stack->ptr->obelus));
    }
    printf("\nThe address of element: %p", p_stack->ptr);
    printf("\nThe value of element: %d%c", p_stack->ptr->number, get_znak_symbol(p_stack->ptr->obelus));
    p_stack->ptr = head;
}

void print_array_stack(stack_array *stack)
{
    for (int i = stack->top_size; i > 0; --i)
    {
        printf("\nThe address of element: %p", &(stack->arr_stack[i - 1]));
        printf("\nThe value of element: %d", stack->arr_stack[i - 1][0]);
        printf("\n The address of znak: %p",&(stack->arr_stack[i - 1][1]));
        printf("\n The value of znak: %c", get_znak_symbol(stack->arr_stack[i - 1][1]));
    }
}


#endif //LAB4_PRINT_STRUCT_H
