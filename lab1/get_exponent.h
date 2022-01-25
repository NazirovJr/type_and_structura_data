//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_GET_EXPONENT_H
#define LAB1_GET_EXPONENT_H
#include "utils.h"
#include "func_helper.h"

int get_exponent(char *number) {
    int is_exponent = 0, is_dot = 0, amount_of_dnum = 0, amount_num  = 0, index_of_exponent = 0, i;
    char exponent[EXPONENT_LENGTH], *remaining;
    long exp;
    for (i = 0; number[i] != '\0'; i++) {

        if (number[i] == '.') {
            is_dot = 1;
        } else if (number[i] == 'E') {
            is_exponent = 1;
        } else if (!is_dot && !is_exponent) {
            amount_num ++;
        } else if (is_dot && !is_exponent) {
            amount_of_dnum++;
        } else if (is_exponent) {
            exponent[index_of_exponent] = number[i];
            index_of_exponent++;
        }
    }
    exponent[index_of_exponent] = '\000';
    if (index_of_exponent)
        number[i - index_of_exponent - 1] = '\0';

    if (amount_of_dnum)
        shift_left(number, i - (amount_of_dnum + index_of_exponent) - (1 + is_exponent));

    exp = strtol(exponent, &remaining, 10) - (amount_of_dnum - 1);
    return exp;
}


short int get_znak(char *num, int index) {
    char sym = '+', exit = 1;
    if (num[index] == '-') {
        exit = -1;
        shift_left(num, index);
    } else if (num[index] == '+') {
        shift_left(num, index);
    }
    return exit;
}


#endif //LAB1_GET_EXPONENT_H
