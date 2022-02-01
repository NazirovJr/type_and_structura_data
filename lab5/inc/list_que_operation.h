//
// Created by nazirov on 09.11.2021.
//

#ifndef LAB5_LIST_QUE_OPERATION_H
#define LAB5_LIST_QUE_OPERATION_H
#include "que_struct.h"
#include "errors.h"
#include "utils.h"
#include <stdlib.h>

double list_que_push(st_list_que **list_que, double value);

double list_que_pop(st_list_que **list_que);

void clear_list_que(st_list_que **list_que);

void list_que_init(st_list_que **list_que);

#endif //LAB5_LIST_QUE_OPERATION_H
