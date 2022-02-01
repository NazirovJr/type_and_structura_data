//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_ERRORS_H
#define LAB4_ERRORS_H
#include <stdlib.h>
#include <ctype.h>
#include "lib_stack_memory.h"
#define STACK_IS_EMPTY -1
#define MEMORY_ERROR -2
#define STACK_OVERFLOW -3
#define INVALID_DATA -4


void clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
#endif //LAB4_ERRORS_H

