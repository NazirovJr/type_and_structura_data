//
// Created by nazirov on 08.10.2021.
//

#ifndef LAB2_ST_SEARCH_H
#define LAB2_ST_SEARCH_H
#include "utils.h"
#include <string.h>
#include "helper_func.h"
int include_sport(char *main_str, char *sr_str);
void st_materic_sports_search(st_travel *travel_data, st_travel *search_result, int st_len, int *rs_len, int i_continent, char *str_sport);
int st_search(st_travel *travel_data, st_travel *sres_travel_data, int st_len, int *rs_len);

void st_materic_sports_search(st_travel *travel_data, st_travel *search_result, int st_len, int *rs_len, int i_continent, char *str_sport)
{
    char *str_mt_1, *str_mt_2;
    char *str_sp_1, *str_sp_2;
    for (int i = 0; i < st_len; ++i)
    {
        str_mt_1 = str_to_lower_case(travel_data[i].travel.materic);str_mt_2 = str_to_lower_case(continent[i_continent]);
        str_sp_1 = str_to_lower_case(travel_data[i].tourism.sports);str_sp_2 = str_to_lower_case(str_sport);
        if (strcmp(str_mt_1, str_mt_2) == 0 && (include_sport(str_sp_1, str_sp_2) == 0))
        {
            search_result[(*rs_len)] = travel_data[i];
            (*rs_len) ++;
        }
        free(str_mt_1);free(str_mt_2);
        free(str_sp_1);free(str_sp_2);
    }
}

int st_search(st_travel *travel_data, st_travel *sres_travel_data, int st_len, int *rs_len)
{
    int rc = 0, index_of_continent;
    char str_mt[MAX_LENGTH_OF_STRING], str_sport[MAX_LENGTH_OF_STRING];
    printf("\n Choose the continent: ");
    index_of_continent = menu_content();
    if (index_of_continent == ERROR_CONSOLE_INPUT)
        return -1;
    printf("\n Enter the sport: ");
    rc = scanf("%s", str_sport);
    if (rc != 1 || !is_buffer_empty())
        return -1;
    st_materic_sports_search(travel_data, sres_travel_data, st_len, rs_len, index_of_continent, str_sport);
    if (!(*rs_len))
        return -2;
    return rc;
}

int include_sport(char *main_str, char *sr_str)
{
    int rc = -1;
    char buffer[MAX_LENGTH_OF_STRING];
    strcpy(buffer, main_str);
    char *value = strtok(buffer, ",");

    while (value) {
        if (strcmp(value, sr_str) == 0) {
            rc = 0;
            break;
        }
        value = strtok(NULL, ",");
    }
    return rc;
}
#endif //LAB2_ST_SEARCH_H
