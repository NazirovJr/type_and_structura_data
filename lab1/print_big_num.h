//
// Created by NazirovJr on 18.09.2021.
//

#ifndef LAB1_PRINT_BIG_NUM_H
#define LAB1_PRINT_BIG_NUM_H
#include "utils.h"

void print_big_int(int *big_int, int len, int exp, int znak)
{
    if (znak > 0)
        printf("+");
    else
        printf("-");

    printf("0.");
    for (int i = 0; i < len - 1; ++i)
        printf("%d", big_int[i]);

    printf("E%d", exp);
}

#endif //LAB1_PRINT_BIG_NUM_H
