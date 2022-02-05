//
// Created by nazirov on 07.12.2021.
//

#include "errors.h"


int check_file(char *filename)
{
    int res = EXIT_SUCCESS;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;
    else if (fgetc(f) == EOF)
        res = EXIT_FAILURE;


    fclose(f);
    return res;
}
