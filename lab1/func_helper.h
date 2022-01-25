//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_FUNC_HELPER_H
#define LAB1_FUNC_HELPER_H
#include "utils.h"
#include "is_correct_number.h"

void shift_left(char *str, int index) {
    for (int i = index; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
}


void ltrim(char *str) {
    int i = 0;
    while (isspace(str[i])) {
        shift_left(str, i);
        i++;
    }
}


void add_exp(int *big_int, int *len, int exp) {
    while (exp != 0)
    {
        big_int[(*len)] = 0;
        exp --;
        (*len) ++;
    }

}


int get_number(char *str_number) {
    int rc = EXIT_SUCCESS;
//    setbuf(stdout, NULL);
    printf("                   ---------|---------|---------|\n");
    printf("Enter float number:");
    scanf("%s", str_number);
    ltrim(str_number);
    if (is_correct_number(str_number) != EXIT_SUCCESS) {
        printf("NOT ok!!!");
        rc = WRONG_DATA;
    }
    return rc;
}

int split_number(char *str_number, int *big_number) {
    int i;
    for (i = 0; str_number[i] != '\0'; ++i)
        big_number[i] = str_number[i] - '0';

    return i;
}


void copy_big_int(int *big_int, int *buffer, int len_of_big_int) {
    for (int i = 0; i < len_of_big_int; ++i) {
        buffer[i] = big_int[i];
    }

}



void shift_left_big_int(int *big_int, int *len, int start) {
    for (int i = start; i < (*len); ++i) {
        big_int[i] = big_int[i + 1];
    }
}

void add_number(int *big_int, int *big_int_len, int number) {
    int counter = 0;
    while (number > 0 || (!counter && number == 0)) {
        for (int i = (*big_int_len) - 1; i >= 0; i--) {
            big_int[i + 1] = big_int[i];
        }
        big_int[0] = number % 10;
        number /= 10;
        (*big_int_len)++;
        counter ++;
    }

}




void normalize_big_int(int *big_int, int *len) {
    int start_index = 0;
    while (big_int[start_index] == 0 && start_index < (*len))
        start_index++;
    start_index--;
    for (int i = start_index; i >= 0; --i) {
        shift_left_big_int(big_int, len, i);
        (*len)--;
    }
}
void  back_normalize_big_int(int *big_int, int *len) {
    int start_index = (*len);
    while (big_int[start_index] == 0 && start_index >= 0)
        start_index --;
    start_index--;
    for (int i = start_index; i >= 0; --i) {
        shift_left_big_int(big_int, len, i);
        (*len)--;
    }
}

#endif //LAB1_FUNC_HELPER_H
