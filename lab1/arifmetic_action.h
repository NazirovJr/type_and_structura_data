//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_DIVIDER_H
#define LAB1_DIVIDER_H

#include "utils.h"
#include "do_bigger.h"
#include "func_helper.h"
#include <limits.h>
#define NINE 9

int divider(int *first_number, int *second_number, int *result, int *len_first, int *len_second, int *len_res);

void multiply_big_int_into_small(int *, int *, int);

void plus(int *, int *, int *, int, int);

void minus_big_int(int *, int *, int, int);

int search_factor(int *, int *, int, int, int);

int get_start_index(int *, int *, int);

int divider(int *first_number, int *second_number, int *result, int *len_first, int *len_second, int *len_res) {
    int buff_num[MANTISSA_MAX_VALUE + 2], flag = 0, exp_counter = 0, len_buff = *len_second, num, res = 0;
    int exp = do_bigger(first_number, second_number, len_first, len_second, (*len_first - exp_counter)), rc;


    if (exp > 0)
        flag ++;

    while (exp > 1) {
        result[*len_res - 1] = ZERO;
        (*len_res)++;
        exp--;
    }


    while (1) {
        if (*len_res > MANTISSA_MAX_VALUE + 1 || !*len_first)
            break;

        num = 1;
        copy_big_int(second_number, buff_num, *len_second);
        len_buff = *len_second;
        int last_index = get_start_index(first_number, buff_num, *len_second);
        if (last_index > *len_first)
            break;

        while ((rc = search_factor(first_number, buff_num, last_index, len_buff, num)), rc == EXIT_SUCCESS)
            num++;

        if (rc == 2)
            num--;


        if (*len_res <= MANTISSA_MAX_VALUE + 1) {
            result[*len_res - 1] = num;
            (*len_res)++;

        }
        else
            break;

        multiply_big_int_into_small(buff_num, &len_buff, num);
        minus_big_int(first_number, buff_num, last_index, len_buff);
        int counter = 0, flag_zero = 1;
        for (int i = last_index; i < *len_first; ++i) {
            if (first_number[i] != 0)
                flag_zero = 0;
            else if (flag_zero)
                counter++;
        }

        normalize_big_int(first_number, len_first);

        if (!*len_first && counter) {
            res = counter;
            break;
        }

        if (counter) {
            int i;
            for (i = 0; i < counter; ++i) {
                result[*len_res - 1] = ZERO;
                (*len_res)++;
            }
        }

        if (!(*len_first))
            break;

        exp = do_bigger(first_number, second_number, len_first, len_second, (*len_first - exp_counter));
        if ((exp == -1 || exp) && !flag) {
            flag ++;
            res = *len_res - 2;
        }

        if (!exp)
            exp_counter ++;

        while (exp > 0) {
            result[*len_res - 1] = ZERO;
            (*len_res)++;
            exp--;
            exp_counter = 0;
        }
    }
    if ((*len_res - 1) == 1 && !flag)
        res ++;


    return res;
}

int get_start_index(int *ft_num, int *sc_num, int sc_len) {
    int index = sc_len;
    for (int i = 0; i < sc_len; ++i) {
        if (ft_num[i] > sc_num[i])
            break;
        else if (ft_num[i] < sc_num[i]) {
            index++;
            break;
        }
    }
    return index;
}

void multiply_big_int_into_small(int *big_int, int *len, int num) {
    int remind = 0, tenth = 10;
    for (int i = ((*len) - 1); i >= 0; --i) {
        int temp = (big_int[i] * num) + remind;
        remind = 0;
        if (temp > 9) {
            remind = temp / tenth;
            temp = temp % tenth;
        }
        big_int[i] = temp;
    }

    if (remind)
        add_number(big_int, len, remind);
}


int search_factor(int *fs_num, int *sc_num, int fs_len, int sc_len, int num) {
    int sc_big_int[LEN_OF_NUMBER_ARR];
    int stop = 1, i = 0;
    copy_big_int(sc_num, sc_big_int, sc_len);
    multiply_big_int_into_small(sc_big_int, &sc_len, num);
    if (fs_len > sc_len)
        stop = EXIT_SUCCESS;
    else if (fs_len < sc_len)
        stop = 2;
    else {
        while (i < fs_len) {
            if (fs_num[i] > sc_big_int[i]) {
                stop = EXIT_SUCCESS;
                break;
            } else if (fs_num[i] < sc_big_int[i]) {
                stop = 2;
                break;
            }
            i++;
        }
    }
    return stop;
}

void minus_big_int(int *ft_num, int *sc_num, int ft_len, int sc_len) {
    int remind = 0, ft_start_index = (ft_len - 1), sc_start_index = sc_len - 1, tenth = 10;
    while (ft_start_index >= 0 && sc_start_index >= 0) {
        int temp = ft_num[ft_start_index] - sc_num[sc_start_index] - remind;
        remind = 0;
        if (temp < 0) {
            remind++;
            temp = temp + tenth;
        }
        ft_num[ft_start_index] = temp;
        ft_start_index--;
        sc_start_index--;
    }

    if (remind && ft_start_index >= 0) {
        while (ft_start_index >= 0 && remind) {
            int temp = ft_num[ft_start_index] - remind;
            remind = 0;
            if (temp < 0) {
                remind++;
                temp = temp + tenth;
            }
            ft_num[ft_start_index] = temp;
            ft_start_index--;
        }
    }

}

void plus(int *ft_num, int *sc_num, int *ft_len, int sc_len, int start) {
    int remind = 0, ft_start_index = (*ft_len - start), sc_start_index = sc_len - 1, tenth = 10;
    while (ft_start_index >= 0 && sc_start_index >= 0) {
        int temp = ft_num[ft_start_index] + sc_num[sc_start_index] + remind;
        remind = 0;
        if (temp > 9) {
            remind = temp / tenth;
            temp = temp % tenth;
        }
        ft_num[ft_start_index] = temp;
        ft_start_index--;
        sc_start_index--;
    }

    if (remind && sc_start_index >= 0) {
        while (sc_start_index >= 0) {

            int temp = sc_num[sc_start_index] + remind;
            remind = 0;
            if (temp > 9) {
                remind = temp / tenth;
                temp = temp % tenth;
            }
            add_number(ft_num, ft_len, temp);
            sc_start_index--;
        }

        if (remind)
            add_number(ft_num, ft_len, remind);
    } else if (remind && ft_start_index >= 0) {
        while (ft_start_index >= 0 && remind) {
            int temp = ft_num[ft_start_index] + remind;
            remind = 0;
            if (temp > 9) {
                remind = temp / tenth;
                temp = temp % tenth;
            }
            ft_num[ft_start_index] = temp;
            ft_start_index--;
        }
        if (remind)
            add_number(ft_num, ft_len, remind);
    } else if (remind) {
        add_number(ft_num, ft_len, remind);
    }

}

#endif //LAB1_DIVIDER_H
