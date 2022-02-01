//
// Created by nazirov on 09.11.2021.
//

#include "../inc/arr_que_operation.h"

void arr_que_init(st_arr_que *arr_que)
{
    arr_que->arr = calloc(MAX_SIZE_OF_QUE, sizeof(int ));
    arr_que->size = 0;
}

double arr_que_push(st_arr_que *arr_que, double value)
{
    if (arr_que->size > MAX_SIZE_OF_QUE)
        return QUE_OVERFLOW;

    arr_que->arr[arr_que->size] = value;
    arr_que->size ++;
    return value;
}


void shift_left_arr_que(st_arr_que *arr_que, size_t index)
{
    for (size_t i = index; i < arr_que->size - 1; ++i)
        arr_que->arr[i] = arr_que->arr[i + 1];
}

double arr_que_pop(st_arr_que *arr_que)
{
    if (arr_que->size < 1)
        return EMPTY_QUE;

    double removed_element;
    removed_element = arr_que->arr[0];
    shift_left_arr_que(arr_que, 0);
    arr_que->arr[arr_que->size - 1] = 0;
    arr_que->size --;
    return removed_element;
}


void arr_que_clear(st_arr_que *arr_que)
{
   arr_que->size = 0;
}
