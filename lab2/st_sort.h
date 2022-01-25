//
// Created by nazirov on 09.10.2021.
//

#ifndef LAB2_ST_SORT_H
#define LAB2_ST_SORT_H
#include "utils.h"
#include <stdint.h>

void st_swap(st_travel *ft_st, st_travel *sc_st)
{
    st_travel *temp;
    temp = ft_st;
    ft_st = sc_st;
    sc_st = temp;
}

void st_bsort_price_by_key(st_key *key_data, int st_len)
{
    st_key temp;
    for (int j = 0; j < st_len; ++j) {
        for (int i = 0; i < st_len - j; ++i) {
            if (key_data[i].count < key_data[i + 1].count)
            {
                temp = key_data[i];
                key_data[i] = key_data[i + 1];
                key_data[i + 1] = temp;
            }
        }
    }

}

void st_selection_sort_by_key(st_key *key_data, int st_len)
{
    int min_index;
    st_key temp;
    for (int i = 0; i < st_len; ++i) {
        min_index = i;
        for (int j = i + 1; j < st_len; ++j) {
            if (key_data[min_index].count < key_data[j].count)
                min_index = j;
        }
        temp = key_data[min_index];
        key_data[min_index] = key_data[i];
        key_data[i] = temp;
    }
}


int comparator_table(const void *val1, const void *val2)
{
    return ((st_travel *)(val1))->travel.demography - ((st_travel *)(val2))->travel.demography;
}

int comparator_keys(const void *val1, const void *val2)
{
    return ((st_key *)(val1))->count - ((st_key *)(val2))->count;
}

void st_bsort_price(st_travel *travel_data, st_key *key_data, int st_len)
{
    int count = 0;
    st_travel temp;
    st_key key_temp;
    for (int j = 0; j < st_len; ++j) {
        for (int i = 0; i < st_len - j; ++i, count ++) {
            if (travel_data[key_data[i].id].travel.demography < travel_data[key_data[i + 1].id].travel.demography)
            {
                temp = travel_data[key_data[i].id];
                travel_data[key_data[i].id] = travel_data[key_data[i + 1].id];
                travel_data[key_data[i + 1].id] = temp;
                key_temp = key_data[i];
                key_data[i] = key_data[i + 1];
                key_data[i + 1] = key_temp;
            }
        }
    }
}


void st_selection_sort(st_travel *travel_data, st_key *key, int st_len)
{
    int min_index;
    st_travel temp;st_key temp_key;
    for (int i = 0; i < st_len; ++i) {
        min_index = i;
        for (int j = i + 1; j < st_len; ++j) {
            if (travel_data[key[min_index].id].travel.demography < travel_data[key[j].id].travel.demography)
                min_index = j;
        }
        temp = travel_data[key[min_index].id];
        travel_data[key[min_index].id] = travel_data[key[i].id];
        travel_data[key[i].id] = temp;
        temp_key = key[min_index];
        key[min_index] = key[i];
        key[i] = temp_key;
    }
}


#endif //LAB2_ST_SORT_H
