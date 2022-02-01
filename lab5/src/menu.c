//
// Created by nazirov on 11.11.2021.
//

#include "../inc/menu.h"

int menu(void) {
    int choice;
    printf("\n\t\tMenu");
    printf("\n--- 1 --->\tArr Que");
    printf("\n--- 2 --->\tList Que");
    printf("\n--- 3 --->\tCompare Efficient");
    printf("\n--- 4 --->\tFragmentation");
    printf("\n--- 0 --->\tExit");
    printf("\nPlease enter your choice: ");
    while (!(scanf("%d", &choice) == 1 && choice <= 4 && choice >= 0)) {
        clean_buffer();
        printf("\nPlease enter again correctly your choice: ");
    }

    return choice;
}

void menu_change(char *str, double *st_time, double *en_time) {
    int choice;
    printf("\nDo you want change the %s interval: ", str);
    printf("\n--- 1 --> Yes");
    printf("\n--- 0 --> No");
    printf("\nEnter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0)) {
        clean_buffer();
        printf("\nPlease enter your choice correctly: ");
    }

    if (choice) {
        printf("\nPlease enter start and end of interval: ");
        while (scanf("%lf%lf", st_time, en_time) != 2 || *st_time < 0 || *en_time < 0) {
            clean_buffer();
            printf("\nPlease enter start and end of interval correctly: ");
        }
    }
}
