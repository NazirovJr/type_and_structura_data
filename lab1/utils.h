//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_UTILS_H
#define LAB1_UTILS_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <math.h>

#define LEN_OF_NUMBER_ARR 44
#define WRONG_DATA -1
#define MANTISSA_MAX_VALUE 30
#define EXPONENT_LENGTH 5
#define EXPONENT_MAX_VALUE 99999
#define EXPONENT_MIN_VALUE -99999
#define MAX_AMOUNT_OF_DOT 1
#define DIVIDING_IN_ZERO -1
#define OVERFLOW_EXPONENT -2
#define ZERO 0

typedef struct {
    char number_string[LEN_OF_NUMBER_ARR];
    short int number_symbol;
    int big_number[LEN_OF_NUMBER_ARR];
    int len;
    int exp;
} big_float_number;

#endif //LAB1_UTILS_H
