//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_DO_BIGGER_H
#define LAB1_DO_BIGGER_H
#include "utils.h"
int do_bigger(int *first_num, int *second_num, int *len_first, int *len_second, int bool_value) {
    int exp = (((*len_first) < (*len_second)) && bool_value >= 0) ? ((*len_second) - (*len_first)):0, stop = 1, broke = 0;
    while (((*len_first) <= (*len_second)) && stop) {
        if ((*len_first) == (*len_second)) {
            for (int i = 0; i < (*len_second); i++) {
                if (first_num[i] > second_num[i]) {
                    stop = 0;
                    broke = 1;
                    break;
                } else if (first_num[i] < second_num[i]) {
                    broke = 2;
                    break;
                }
            }
            if (!broke) {
                stop = 0;
                if (!exp) {
                    exp = -1;
                }
            }
        }
        if (stop)
        {
            first_num[(*len_first)] = 0;
            (*len_first) ++;
        }
    }

    return exp;
}

#endif //LAB1_DO_BIGGER_H
