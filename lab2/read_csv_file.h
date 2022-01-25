//
// Created by nazirov on 06.10.2021.
//

#ifndef LAB2_READ_CSV_FILE_H
#define LAB2_READ_CSV_FILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "helper_func.h"

long convert_to_int(char *str)
{
   char *ptr = NULL;
   long ret;
   int rc = 0;
   ret = strtol(str, &ptr, 10);
   if (!*ptr || !ret)
	   rc = ERROR_FILE;
   return ret;
}

int read_csv(int *row, FILE *fp, st_travel *travel_data) {
    char buffer[1024];
    int column = 0, rc = 0, flag = 0;
    char *check;

    while (1)
    {
        check = fgets(buffer, 1024, fp);
        if (check == NULL)
            break;

        if ((*row) > MAX_LENGTH_OF_STRUCT)
            return TABLE_OVER_FLOW;

        column = 0;


        // Splitting the data
        char *value = strtok(buffer, "; ");

        while (value) {
            value = trim(value);
            switch (column) {
                case 0: {
					if (strcpy(travel_data[(*row)].travel.country, value) == NULL)
					    flag = 1;
                    break;
                }
                case 1: {
                    rc = (int) convert_to_int(value);
                    if (rc == ERROR_FILE)
                        flag = 1;
                    else
					    travel_data[(*row)].travel.demography = rc;
                    break;
                }
                case 2: {
					if (strcpy(travel_data[(*row)].travel.capital, value) == NULL)
					    flag = 1;
                    break;
                }
                case 3: {
					if (strcpy(travel_data[(*row)].travel.materic, value) == NULL)
					    flag = 1;
                    break;
                }
                case 4: {
                    rc = (int) convert_to_int(value);
                    if (rc == ERROR_FILE)
                        flag = 1;
                    else
					    travel_data[(*row)].travel.is_required_vicinity = rc;
                    break;

                }
                case 5: {
                    rc = (int) convert_to_int(value);
                    if (rc == ERROR_FILE)
                        flag = 1;
                    else
                        travel_data[(*row)].travel.is_psr_test_required = rc;
                    break;

                }
                case 6: {
					if (strcpy(travel_data[(*row)].tourism.essential_type_of_tourism, value) == NULL)
					    flag = 1;
                    break;

                }
                case 7: {
					if (strcpy(travel_data[(*row)].tourism.feature_of_tourism, value) == NULL)
                        flag = 1;
					break;
                }
                case 8: {
                    rc = (int) convert_to_int(value);
                    if (rc == ERROR_FILE)
                        flag = 1;
                    else
					    travel_data[(*row)].travel.time_of_way = rc;
                    break;

                }
                case 9: {
					if (stpcpy(travel_data[(*row)].tourism.sports, value) == NULL)
					    flag = 1;
                    break;

                }
                case 10: {
                    rc = (int) convert_to_int(value);
                    if (rc == ERROR_FILE)
                        flag = 1;
                    else
					    travel_data[(*row)].travel.min_budget = rc;
                    break;
                }
                default:
                    break;


            }

            value = strtok(NULL, "; ");
            column++;
        }
        (*row)++;
    }
    return flag;
}


static short upload_from_file(st_travel *const table, int *st_len)
{
    FILE *f = NULL;

    clear_table(table, *st_len);

    if ((f = fopen(FILE_NAME, "r")) == NULL)
    {
        return ERROR_FILE;
    }


    if (read_csv(st_len, f, table))
    {
        return ERROR_FILE;
    }

    fclose(f);

    return EXIT_SUCCESS;
}
#endif //LAB2_READ_CSV_FILE_H
