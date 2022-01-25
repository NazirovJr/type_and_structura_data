//
// Created by nazirov on 06.10.2021.
//

#ifndef LAB2_ADD_FILE_H
#define LAB2_ADD_FILE_H
#include "utils.h"
#include <stdlib.h>
#include "print_file.h"
#include "helper_func.h"
#include "menu.h"

int check_element(int rc, int cmp);

int add_file(int *st_len, st_travel *travel_data)
{
    int rc = 0, flag = 0, aa_value;
    printf("How many countries you want to add: ");
    rc = scanf("%d", &aa_value);
    if (rc != 1 || !is_buffer_empty())
        return ERROR_CONSOLE_INPUT;
    while (aa_value > 0)
    {
        printf("\n Name of country: ");
        rc = scanf("%s", travel_data[*st_len].travel.country);
        if ((flag = check_element(rc, ONE)))
            break;

        printf("\n Amount of People in this country: ");
        rc = scanf("%ld", &travel_data[*st_len].travel.demography);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n Capital of country: ");
        rc = scanf("%s", travel_data[*st_len].travel.capital);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n In which continent it located: ");
        rc = menu_content();
        if (rc == ERROR_CONSOLE_INPUT)
        {
            flag = 1;
            break;
        }
        strcpy(travel_data[*st_len].travel.materic, continent[rc]);
        printf("\n Required the vaccines (Yes: 1, No: 0): ");
        rc = scanf("%hd", &travel_data[*st_len].travel.is_required_vicinity);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n Required the Covid-19 test (Yes: 1, No : 0): ");
        rc = scanf("%hd", &travel_data[*st_len].travel.is_psr_test_required);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n The essential entertainment: ");
        rc = scanf("%s", travel_data[*st_len].tourism.essential_type_of_tourism);
        if ((flag = check_element(rc,ONE)))
            break;
        printf("\n The characteristic of this entertainment: ");
        rc = scanf("%s", travel_data[*st_len].tourism.feature_of_tourism);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n How many times will get the road until the country: ");
        rc = scanf("%d", &travel_data[*st_len].travel.time_of_way);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n Types of sport in this country: ");
        rc = scanf("%s", travel_data[*st_len].tourism.sports);
        if ((flag = check_element(rc, ONE)))
            break;
        printf("\n The minimum budget for traveling to this country:  ");
        rc = scanf("%d", &travel_data[*st_len].travel.min_budget);
        if ((flag = check_element(rc, ONE)))
            break;
        aa_value --;
        (*st_len) ++;
    }
    return flag ? ERROR_CONSOLE_INPUT : flag;
}

int check_element(int rc, int cmp)
{
    int flag = 0;
    if (rc != cmp || !is_buffer_empty())
        flag = 1;
    return flag;
}
#endif //LAB2_ADD_FILE_H

