//
// Created by nazirov on 09.10.2021.
//

#ifndef LAB2_HELPER_FUNC_H
#define LAB2_HELPER_FUNC_H
#include <stdio.h>
#include <ctype.h>

void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

long is_buffer_empty()
{
    long num;
    fseek (stdin, 0, SEEK_END);
    num = ftell(stdin);
    return num;
}

char *trim(char *str)
{
    char *end;


    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)
        return str;


    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';

    return str;
}

char *str_to_lower_case(char *s)
{
    char *str_l = calloc(strlen(s), sizeof(char));
    size_t i = 0;
    for (; *(s + i) != '\0'; ++i) {
        str_l[i] = tolower((unsigned char)s[i]);
    }
    str_l[i] = '\0';
    return str_l;
}

static void clear_table(st_travel *const table, int st_len)
{
    for (int i = 0; i < st_len; i++)
    {
        table->travel.min_budget = 0;
        table->travel.time_of_way = 0;
        table->travel.is_required_vicinity = 0;
        table->travel.is_psr_test_required = 0;
        table->travel.materic[0] = '\0';
        table->travel.capital[0] = '\0';
        table->travel.country[0] = '\0';
        table->tourism.feature_of_tourism[0] = '\0';
        table->tourism.essential_type_of_tourism[0] = '\0';
        table->tourism.sports[0] = '\0';
    }
}



#endif //LAB2_HELPER_FUNC_H
