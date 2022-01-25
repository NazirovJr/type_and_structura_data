//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_IS_CORRECT_NUMBER_H
#define LAB1_IS_CORRECT_NUMBER_H
#include "utils.h"

int is_correct_number(char *number) {
    int exit = EXIT_SUCCESS, dot_counter = 0, mantissa_counter = 1, exponent_counter = 1, is_exponent = 0;
    for (int i = 0; number[i] != '\0' && i < LEN_OF_NUMBER_ARR; i++) {
        int condition_znak = i == 0 && !isdigit(number[i]) && number[i] != '.' && number[i] != '+' && number[i] != '-';
        int condition_exp = i != 0 && !isdigit(number[i]) && number[i] != '.' && number[i] != 'E';
        int condition_sym = condition_exp && !(number[i - 1] == 'E' && (number[i] == '+' || number[i] == '-'));
        int over_flow_condition = mantissa_counter > MANTISSA_MAX_VALUE || exponent_counter > EXPONENT_LENGTH ||
                                  dot_counter > MAX_AMOUNT_OF_DOT;

        if (condition_znak || condition_sym && condition_exp || over_flow_condition) {
            exit = EXIT_FAILURE;
            break;
        }

        if (number[i] == 'E') {
            is_exponent++;
        }

        if (number[i] == '.' && is_exponent) {
            exit = EXIT_FAILURE;
            break;
        } else if (number[i] == '.') {
            dot_counter++;
        } else if (!is_exponent && isdigit(number[i])) {
            mantissa_counter++;
        } else if (isdigit(number[i])) {
            exponent_counter++;
        }

        if (is_exponent > 1) {
            exit = EXIT_FAILURE;
            break;
        }
    }
    return exit;
}


#endif //LAB1_IS_CORRECT_NUMBER_H
