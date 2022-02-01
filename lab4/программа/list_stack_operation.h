//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_LIST_STACK_OPERATION_H
#define LAB4_LIST_STACK_OPERATION_H


#include "stack_struct.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "lib_stack_memory.h"

int get_res_operation(stack_list **stack, int res);


int *list_el_pop(stack_list **stack) {
    node *temp = NULL;

    if ((*stack)->ptr == NULL)
        return NULL;

    int *p_pop_value = &((*stack)->ptr->number);
    temp = (*stack)->ptr;
    (*stack)->ptr = (*stack)->ptr->prev;
    free(temp);
    return p_pop_value;
}

int list_el_push(stack_list **stack, int num, int znak) {
    node *temp = stack_list_el_init(num, znak);
    if (temp == NULL)
        return MEMORY_ERROR;

    temp->prev = (*stack)->ptr;
    (*stack)->ptr = temp;
    return EXIT_SUCCESS;
}

int arr_el_push(stack_array *stack, int num, int znak) {
    if (stack->top_size >= stack->size)
        return STACK_OVERFLOW;

    stack->arr_stack[stack->top_size][0] = num;
    stack->arr_stack[stack->top_size][1] = znak;
    stack->top_size++;
    return EXIT_SUCCESS;
}

int realloc_free_array_area(stack_array *stack) {
    int **p = realloc(stack, stack->size * stack->size * sizeof(int *)), rc = EXIT_SUCCESS;
    if (p) {
        stack->arr_stack = p;
        rc = EXIT_FAILURE;
    }
    return rc;
}

int arr_el_push_free_area(stack_array *stack, int *num) {
    int rc = EXIT_SUCCESS;
    if (stack->top_size >= stack->size) {
        rc = realloc_free_array_area(stack);
    }
    if (rc == EXIT_SUCCESS) {
        stack->arr_stack[stack->top_size] = num;
        stack->top_size++;
    }
    return rc;
}

void copy_array_stack(stack_array *stack, stack_array *stack_copy) {
    while (stack_copy->top_size < stack->top_size)
        arr_el_push(stack_copy, stack->arr_stack[stack_copy->top_size][0], stack->arr_stack[stack_copy->top_size][1]);
}


node *copy_list_stack(node *head) {
    node *current = head;    // used to iterate over the original list
    node *newList = NULL;    // head of the new list
    node *tail = NULL;       // point to the last node in a new list

    while (current != NULL) {
        // special case for the first new node
        if (newList == NULL) {
            newList = (node *) malloc(sizeof(node));
            newList->number = current->number;
            newList->obelus = current->obelus;
            newList->prev = NULL;
            tail = newList;
        } else {
            tail->prev = (node *) malloc(sizeof(node));
            tail = tail->prev;
            tail->number = current->number;
            tail->obelus = current->obelus;
            tail->prev = NULL;
        }
        current = current->prev;
    }

    return newList;
}

int *arr_el_pop(stack_array *stack) {
    if (!stack->top_size)
        return NULL;
    int *p_removing_num = stack->arr_stack[stack->top_size];
    stack->top_size--;
    return p_removing_num;
}

int stack_arr_el_operation(stack_array *stack) {
    int res = 0;
    if (stack->top_size > 1)
    {
        res = stack->arr_stack[stack->top_size - 1][0];
        res *= stack->arr_stack[stack->top_size - 2][1];
    }
    else
        res = stack->arr_stack[stack->top_size - 1][0];

    arr_el_pop(stack);
    while (stack->top_size > 1)
    {
        res += stack->arr_stack[stack->top_size - 1][0] * stack->arr_stack[stack->top_size - 2][1];
        arr_el_pop(stack);
    }
    res += stack->arr_stack[stack->top_size - 1][0];
    arr_el_pop(stack);
    return res;

}

int stack_list_el_operation(stack_list **stack)
{
    int res = 0;
    if ((*stack)->ptr->prev)
    {
        res = (*stack)->ptr->number;
        res *= (*stack)->ptr->prev->obelus;
    }
    else
        res = (*stack)->ptr->number;

    list_el_pop(stack);
    while ((*stack)->ptr->prev)
    {
        res += (*stack)->ptr->number * (*stack)->ptr->prev->obelus;
        list_el_pop(stack);
    }
    res += (*stack)->ptr->number;
    list_el_pop(stack);
    return res;
}

int get_res_operation(stack_list **stack, int res) {
    switch ((*stack)->ptr->obelus) {
        case PLUS: {
            res += (*stack)->ptr->number;
            break;
        }
        case MINUS: {
            res -= (*stack)->ptr->number;
            break;
        }
            /*  case MULTIPLY:
              {
                  res *= (*stack)->ptr->number;
                  break;
              }
              case DIVIDE:
              {
                  res /= (*stack)->ptr->number;
                  break;
              }*/
        default:
            break;
    }
    return res;
}

void clean_list_stack(stack_list **stack) {
    while ((*stack)->ptr)
        list_el_pop(stack);
}

void clean_arr_stack(stack_array *stack) {
    while (stack->top_size)
        arr_el_pop(stack);
}


int ck_list_entered_data(stack_list **stack, char *str) {
    int rc = EXIT_SUCCESS, znak = PLUS, i = 0, flag = 0, obelus = 1, counter = 0;
    int number = 0, tenth = 1;
    while (!isdigit(str[i]) && rc == EXIT_SUCCESS)
    {
        if (str[i] == '-')
            obelus = -1;
        else if (str[i] != '+' && !isspace(str[i]) && !iscntrl(str[i]))
            rc = EXIT_FAILURE;
        i++;
    }

    while (str[i] != '\000' && str[i] != '\377' && rc == EXIT_SUCCESS) {
        if (isdigit(str[i])) {
            number *= tenth;
            number += ((str[i] - '0') * obelus);
            obelus = 1;
            tenth *= 10;
            flag = 0;
        } else if ((str[i] == '+' || str[i] == '-') && !flag) {
            flag = 1;
            if (str[i] == '+')
                znak = PLUS;
            else
                znak = MINUS;
        } else if (!isspace(str[i]) && !iscntrl(str[i]))
            rc = INVALID_DATA;

        if (flag) {
            list_el_push(stack, number, znak);
            tenth = 1;
            number = 0;
            znak = PLUS;
            counter ++;
        }
        i++;
    }
    if (number)
    {
        list_el_push(stack, number, znak);
        tenth = 1;
        number = 0;
        counter ++;
    }
    return rc == EXIT_SUCCESS && !counter ? EXIT_FAILURE : rc;
}

int ck_entered_data(stack_array *stack, char *str) {
    int rc = EXIT_SUCCESS, znak = PLUS, i = 0, flag = 0, obelus = 1, counter = 0;
    int number = 0, tenth = 1;
    while (!isdigit(str[i]) && rc == EXIT_SUCCESS)
    {
        if (str[i] == '-')
            obelus = -1;
        else if (str[i] != '+' && !isspace(str[i]) && !iscntrl(str[i]))
            rc = EXIT_FAILURE;
        i++;
    }

    while (str[i] != '\000' && str[i] != '\377' && rc == EXIT_SUCCESS) {
        if (isdigit(str[i])) {
            number *= tenth;
            number += ((str[i] - '0') * obelus);
            obelus = 1;
            tenth *= 10;
            flag = 0;
        } else if ((str[i] == '+' || str[i] == '-') && !flag) {
            flag = 1;
            if (str[i] == '+')
                znak = PLUS;
            else
                znak = MINUS;
        } else if (!isspace(str[i]) && !iscntrl(str[i]))
            rc = INVALID_DATA;

        if (flag) {
            if (stack->top_size >= stack->size)
                rc = STACK_OVERFLOW;
            else
            {
                arr_el_push(stack, number, znak);
                tenth = 1;
                number = 0;
                znak = PLUS;
                counter++;
            }
        }
        i++;
    }
    if (number)
    {
        if (stack->top_size >= stack->size)
            rc = STACK_OVERFLOW;
        else
        {
            arr_el_push(stack, number, znak);
            tenth = 1;
            number = 0;
            counter++;
        }
    }
    return rc == EXIT_SUCCESS && !counter ? EXIT_FAILURE : rc;
}

#endif //LAB4_LIST_STACK_OPERATION_H
