//
// Created by nazirov on 08.10.2021.
//

#ifndef LAB2_REMOVE_ELEMENT_FROM_STRUCT_H
#define LAB2_REMOVE_ELEMENT_FROM_STRUCT_H
#include "print_file.h"

void shift_left_struct(st_travel *travel_data, int st_len, int start_index);

int remove_struct_element(st_travel *travel_data, int *st_len, int st_element_index)
{
    if (st_element_index > *st_len || st_element_index < 0)
        return -1;
    shift_left_struct(travel_data, *st_len, st_element_index);
    (*st_len) --;
    return 0;
}

void shift_left_struct(st_travel *travel_data, int st_len, int start_index)
{
    for (int i = start_index; i < st_len - 1; ++i)
        travel_data[i] = travel_data[i + 1];
}
#endif //LAB2_REMOVE_ELEMENT_FROM_STRUCT_H
