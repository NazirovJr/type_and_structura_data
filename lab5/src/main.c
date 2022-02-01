#include <stdio.h>
#include "../inc/timer.h"
#include "../inc/menu.h"
#include "../inc/process.h"

int main() {
    int choice = 1;

    while (choice) {
        choice = menu();
        if (choice == 1)
            arr_que_model();
        else if (choice == 2)
            list_que_model();
        else if (choice == 3)
            test_timer();
        else if (choice == 4)
            fragmentation_que_model();
    }

    return 0;
}
