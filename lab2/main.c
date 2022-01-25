#include <stdio.h>
#include "utils.h"
#include "read_csv_file.h"
#include "add_file.h"
#include "remove_element_from_struct.h"
#include "st_search.h"
#include "menu.h"
#include "helper_func.h"
#include "st_sort.h"
#include "st_key.h"
#include "timer.h"
void st_proccess_print(FILE *file_data, char *str, st_travel *travel_data, int st_len);

int main(int argc, char **argv) {
    int st_len = 0, rc = 0, menu_var = 1;
    st_travel travel_data[MAX_LENGTH_OF_STRUCT];
    if (argc != 2)
        return ARG_ERROR;
    FILE *file_data = fopen(argv[1], "r");
    if (!file_data) {
        printf("Error opening file!");
        return ERROR_FILE;
    }
    if ((rc = read_csv(&st_len, file_data, travel_data))) {
        printf("Error data please check the data and try again!!!");
        rc = EXIT_FAILURE;
        fclose(file_data);
    }
    else {
        fclose(file_data);
        if (!st_len)
        {
            printf("Empty File!!!");
            rc = EXIT_FAILURE;
        }
        else if (rc == TABLE_OVER_FLOW)
            printf("Table overflow!");
        else
        {
            st_key key_data[MAX_LENGTH_OF_STRUCT];
            st_initialize_key(key_data, travel_data, st_len);
            while (menu_var) {
                menu_var = menu();
                if (menu_var < 0) {
                    printf(menu_var == -1 ? "Invalid data please please enter correct variant!!!"
                                          : "Sorry which variant you choose is not exists");
                }
                if (menu_var != 6 && !st_len) {
                    printf("Empty Table!!!");
                    continue;
                }

                switch (menu_var) {
                    case 1: {
                        st_print_table(travel_data, st_len);
                        break;
                    }
                    case 2:
                    {
                        if (!st_len)
                            printf("Data is empty!!!");
                        else {
                            st_bsort_price_by_key(key_data, st_len);
                            printf("Data is sorted !!!");
                        }
                        break;
                    }
                    case 3:
                    {
                        if (!st_len)
                            printf("Data is Empty!!!");
                        else {
                            st_selection_sort_by_key(key_data, st_len);
                            printf("Data is sorted !!!");
                        }
                        break;
                    }
                    case 4:
                    {
                        if (!st_len)
                            printf("Data is empty!!!");
                        else {
                            st_bsort_price(travel_data, key_data, st_len);
                            printf("Data is sorted !!!");
                        }
                        break;
                    }
                    case 5:
                    {
                        if (!st_len)
                            printf("Data is Empty!!!");
                        else {
                            st_selection_sort(travel_data, key_data, st_len);
                            printf("Data is sorted !!!");
                        }
                        break;
                    }
                    case 6: {
                        if (st_len > MAX_LENGTH_OF_STRUCT)
                            printf("TABLE OVER FLOW!!!");
                        else
                        {
                            if (add_file(&st_len, travel_data) == ERROR_CONSOLE_INPUT) {
                                printf("Invalid data please enter correct data!!!");
                                clean_buffer();
                            } else {
                                st_proccess_print(file_data, argv[1], travel_data, st_len);
                                add_key(key_data, travel_data, st_len);
                            }
                        }
                        break;
                    }
                    case 7: {
                        st_print_table(travel_data, st_len);
                        int in_del_st_elem = -1, check;
                        printf("\n Enter index of removing element: ");
                        check = scanf("%d", &in_del_st_elem);
                        if (check != 1) {
                            printf("Invalid data please enter correct data!!!");
                            clean_buffer();
                        } else if (in_del_st_elem > st_len || in_del_st_elem < 1) {
                            printf("Not such as element in file");
                            clean_buffer();
                        } else {
                            remove_struct_element(travel_data, &st_len, in_del_st_elem - 1);
                            remove_key(key_data, st_len, in_del_st_elem - 1);
                            st_proccess_print(file_data, argv[1], travel_data, st_len);
                            printf("Data successfully deleted");
                        }
                        break;
                    }
                    case 8: {
                        int st_res_len = 0, check = 0;
                        st_travel res_search[MAX_LENGTH_OF_STRUCT];
                        if ((check = st_search(travel_data, res_search, st_len, &st_res_len)) < 0) {
                            if (check == -1)
                                printf("Invalid data please enter correct data!!!");
                            else if (check == -2)
                                printf("Not such elements in file");
                            clean_buffer();
                        } else {
                            st_print_table(res_search, st_res_len);
                        }
                        break;
                    }
                    case 9: {
                        st_proccess_print(file_data, argv[1], travel_data, st_len);
                        break;
                    }
                    case 10:
                    {
                        print_key_table(key_data, st_len);
                        break;
                    }
                    case 11:
                    {
                        st_initialize_key(key_data, travel_data, st_len);
                        break;
                    }
                    case 12:
                    {
                        st_print_with_key_table(travel_data, key_data, st_len);
                        break;
                    }
                    case 13:
                    {
                        time_table_sort(travel_data, key_data, st_len);
                        measurer_time_table_sort(travel_data, key_data, st_len);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        printf("Sorry not such variant please try again");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}


void st_proccess_print(FILE *file_data, char *str, st_travel *travel_data, int st_len) {
    fclose(file_data);
    file_data = fopen(str, "w");
    if (file_data)
    {
        fprint_struct(file_data, travel_data, st_len);
        fclose(file_data);
        file_data = fopen(str, "r");
    }
}
