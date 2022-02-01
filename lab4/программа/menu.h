//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_MENU_H
#define LAB4_MENU_H

#include "errors.h"
#include <stdio.h>

#define MAX_CHOICE 12

void menu(int *choice) {
    int rc = EXIT_FAILURE;

    printf("\n\t\tMenu");
    printf("\n\n -- Array Stack -- ");
    printf("\n\t\t- 1 - Add element in stack");
    printf("\n\t\t- 2 - Remove element from stack");
    printf("\n\t\t- 3 - Generate the data");
    printf("\n\t\t- 4 - Solve operation from stack");
    printf("\n\t\t- 5 - Print stack");
    printf("\n\n -- List Stack -- ");
    printf("\n\t\t- 6 - Add element in stack");
    printf("\n\t\t- 7 - Remove element from stack");
    printf("\n\t\t- 8 - Generate the data");
    printf("\n\t\t- 9 - Solve operation from stack");
    printf("\n\t\t- 10 - Print stack");
    printf("\n\n -- Compare the efficient of array and list stack -- ");
    printf("\n\t\t- 11 - Compare");
    printf("\n\n -- Exit Program -- ");
    printf("\n\t\t- 0 - Exit");
    printf("\n\n\t\t- 12 - Print the address of deleted element");
    printf("\n\nPlease enter your choice: ");
    while (rc == EXIT_FAILURE) {
        if (scanf("%d", choice) != 1 || *choice > MAX_CHOICE || *choice < 0) {
            printf("\nInvalid data!");
            printf("\nPlease enter the correct value again: ");
            clean_buffer();
        }
        else
            rc = EXIT_SUCCESS;
    }
}

#endif //LAB4_MENU_H
