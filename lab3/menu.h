//
// Created by nazirov on 16.10.2021.
//

#ifndef LAB3_MENU_H
#define LAB3_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

int menu(int *choice) {
    int rc = EXIT_SUCCESS;
    printf("\t\t--Menu--");
    printf("\n- 1 - Enter the array");
    printf("\n- 2 - Generate the array");
    printf("\n- 3 - Check efficiency");
    printf("\n\nEnter your choice: ");
    if (scanf("%d", choice) != 1) {
        rc = CONSOLE_ERROR;
        printf("Invalid data!!!");
    } else if (*choice < 1 || *choice > 3) {
        rc = CONSOLE_ERROR;
        printf("Your choice not founded!");
    }
    return rc;
}

#endif //LAB3_MENU_H
