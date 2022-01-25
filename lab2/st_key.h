//
// Created by nazirov on 09.10.2021.
//

#ifndef LAB2_ST_KEY_H
#define LAB2_ST_KEY_H
#include "utils.h"
void st_initialize_key(st_key *key_data, st_travel *travel_data, int st_len) {
    for (int i = 0; i < st_len; ++i){
        key_data[i].id = i;
        key_data[i].count = travel_data[i].travel.demography;
    }
}

void st_key_shift_left(st_key *key_data, int st_len, int start_index)
{
    for (int i = start_index; i < st_len - 1; ++i)
        key_data[i] = key_data[i + 1];
}

void add_key(st_key *key_data, st_travel *travel, int st_len)
{
    key_data[st_len - 1].id = st_len - 1;
    key_data[st_len - 1].count = travel[st_len - 1].travel.demography;
}

int remove_key(st_key *key_data, int st_len, int remove_index)
{
    if (remove_index > st_len || remove_index < 0)
        return -1;
    st_key_shift_left(key_data, st_len, remove_index);
    return 0;

}
#endif //LAB2_ST_KEY_H
