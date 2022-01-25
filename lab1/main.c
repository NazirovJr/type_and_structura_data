#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_exponent.h"
#include "func_helper.h"
#include "arifmetic_action.h"
#include "print_big_num.h"
#include "utils.h"
#include "round_big_int.h"
#include "print_law_of_entering_value.h"

int main() {
    print_law();
    int rc = EXIT_SUCCESS;
    big_float_number first_number, second_number, result_number;
    rc = get_number(first_number.number_string);
    if (rc != EXIT_SUCCESS) {
        printf("INVALID DATA");
        return rc;
    }

    rc = get_number(second_number.number_string);
    if (rc != EXIT_SUCCESS) {
        printf("INVALID DATA");
        return rc;
    }

    first_number.exp = get_exponent(first_number.number_string);
    second_number.exp = get_exponent(second_number.number_string);
    result_number.exp = first_number.exp - second_number.exp;
    first_number.number_symbol = get_znak(first_number.number_string, 0);
    second_number.number_symbol = get_znak(second_number.number_string, 0);
    first_number.len = split_number(first_number.number_string, first_number.big_number);
    second_number.len = split_number(second_number.number_string, second_number.big_number);
    normalize_big_int(first_number.big_number, &first_number.len);
    normalize_big_int(second_number.big_number, &second_number.len);
    if (second_number.len < 1)
    {
        printf("INVALID DATA");
        return DIVIDING_IN_ZERO;
    }

    if (first_number.len < 1)
        printf("0.0E0");
    else
    {
        if (result_number.exp > EXPONENT_MAX_VALUE || result_number.exp < EXPONENT_MIN_VALUE)
        {
            printf("EXPONENT OVERFLOW");
            return OVERFLOW_EXPONENT;
        }

        result_number.len = 1;
        result_number.number_symbol = (short int) (first_number.number_symbol * second_number.number_symbol);
        result_number.exp += divider(first_number.big_number, second_number.big_number, result_number.big_number, &first_number.len,
                &second_number.len, &result_number.len);
        if (result_number.exp > EXPONENT_MAX_VALUE || result_number.exp < EXPONENT_MIN_VALUE)
        {
            printf("EXPONENT OVERFLOW");
            return OVERFLOW_EXPONENT;
        }
        int exp = result_number.exp;
        if (result_number.len > MANTISSA_MAX_VALUE)
            round_big_int(result_number.big_number, &result_number.len);
        result_number.exp = exp;
        print_big_int(result_number.big_number, result_number.len, result_number.exp, result_number.number_symbol);

    }

    return rc;
}

