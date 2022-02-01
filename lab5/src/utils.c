//
// Created by nazirov on 11.11.2021.
//

#include "../inc/utils.h"


void clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
