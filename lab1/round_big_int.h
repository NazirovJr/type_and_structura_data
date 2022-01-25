//
// Created by NazirovJr on 18.09.2021.
//

#ifndef RK_2_MAIN_ROUND_BIG_INT_H
#define RK_2_MAIN_ROUND_BIG_INT_H
#include "func_helper.h"

void round_big_int(int *big_int, int *len)
{
    int remind, tenth = 10, flag = 0;
    if (big_int[(*len) - 2] > 4)
        remind = 1;
    (*len) -= 2;
    for (int i = (*len) - 1; i >= 0 && remind != 0; --i) {
        int temp = big_int[i] + remind;
        remind = 0;
        if (temp > 9) {
            remind = temp / tenth;
            temp = temp % tenth;
            flag = 1;
        }
        if (flag || temp < 5)
            big_int[i] = temp;
        else
            big_int[i - 1] = temp;

    }
//
    if (remind)
        add_number(big_int, len, remind);
}
#endif //RK_2_MAIN_ROUND_BIG_INT_H
