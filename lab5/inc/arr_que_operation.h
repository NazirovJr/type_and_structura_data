//
// Created by nazirov on 09.11.2021.
//

#ifndef LAB5_ARR_QUE_OPERATION_H
#define LAB5_ARR_QUE_OPERATION_H
#include "que_struct.h"
#include "errors.h"
#include "utils.h"
#include <stdlib.h>

double arr_que_push(st_arr_que *arr_que, double value);

void shift_left_arr_que(st_arr_que *arr_que, size_t index);

double arr_que_pop(st_arr_que *arr_que);

void arr_que_clear(st_arr_que *arr_que);

void arr_que_init(st_arr_que *arr_que);

#endif //LAB5_ARR_QUE_OPERATION_H
