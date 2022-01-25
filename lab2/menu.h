//
// Created by nazirov on 09.10.2021.
//

#ifndef LAB2_MENU_H
#define LAB2_MENU_H
#include <stdio.h>
#include "utils.h"
#include "helper_func.h"

int menu(void)
{
    int rc = 0, variant;
    printf("\n\t\tMenu");
    printf("\n - 1 - Print travel data");
    printf("\n - 2 - Sort travel data by key with bubble sort");
    printf("\n - 3 - Sort travel data by key with  sort");
    printf("\n - 4 - Sort travel data with bubble sort");
    printf("\n - 5 - Sort travel data with  sort");
    printf("\n - 6 - Add new country into travel data");
    printf("\n - 7 - Remove country from travel data");
    printf("\n - 8 - Search country with parameters of continent and sport");
    printf("\n - 9 - Record the travel data into file");
    printf("\n - 10 - Print key");
    printf("\n - 11 - Re initialize the key");
    printf("\n - 12 - Print table with key");
    printf("\n - 13 - Show Efficient of sorting with key and table;");
    printf("\n - 0 - Exit");
    printf("\n\nChoose the variant from menu: ");
    rc = scanf("%d", &variant);
    if (rc != 1 || !is_buffer_empty())
        variant = -1;
    else if (variant > THIRTEEN)
        variant = -2;
    return variant;
}

int menu_content()
{
    printf("\n - 1 - Asia");
    printf("\n - 2 - Europe");
    printf("\n - 3 - America");
    printf("\n - 4 - Australia");
    printf("\n - 5 - Africa");
    printf("\n Choose continent: ");
    int id_of_content, rc;
    rc = scanf("%d", &id_of_content);
    if (rc != 1 || id_of_content < ONE || id_of_content > FIFE)
        return ERROR_CONSOLE_INPUT;
    return id_of_content - 1;
}
#endif //LAB2_MENU_H
