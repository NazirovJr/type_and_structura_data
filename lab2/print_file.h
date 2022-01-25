//
// Created by nazirov on 07.10.2021.
//

#ifndef LAB2_PRINT_FILE_H
#define LAB2_PRINT_FILE_H
#include "utils.h"
#define GHZ 1500000000

void fprint_struct(FILE *write_file, st_travel *data_travel, int len)
{

    for (int i = 0; i < len; ++i)
    {
        fprintf(write_file, "%s;", data_travel[i].travel.country);
        fprintf(write_file, "%ld;", data_travel[i].travel.demography);
        fprintf(write_file, "%s;", data_travel[i].travel.capital);
        fprintf(write_file, "%s;", data_travel[i].travel.materic);
        fprintf(write_file, "%d;", data_travel[i].travel.is_required_vicinity);
        fprintf(write_file, "%d;", data_travel[i].travel.is_psr_test_required);
        fprintf(write_file, "%s;", data_travel[i].tourism.essential_type_of_tourism);
        fprintf(write_file, "%s;", data_travel[i].tourism.feature_of_tourism);
        fprintf(write_file, "%d;", data_travel[i].travel.time_of_way);
        fprintf(write_file, "%s;", data_travel[i].tourism.sports);
        fprintf(write_file, "%d;", data_travel[i].travel.min_budget);
        fprintf(write_file, "%s", " \n");
    }
}


void print_sorts_vs_results(short size, int64_t total_ticks, short sort_type, short table_type)
{
    printf("Сортировка %s с помощью %s.\n", table_type ? "таблицы" : "массива ключей", sort_type ? "QuickSort" : "пузырька");
    printf("%Ild тактов, %ld секунд\n", total_ticks, total_ticks / GHZ);
}




void st_print_with_key_table(st_travel *travel, st_key *key_data, int st_len)
{
    if (st_len == 0)
    {
        printf("\nTable is empty!\n");
        return;
    }

    printf("\n╒═══════╤════════════════════════════════╤════════════════╤════════════════════════════════╤═══════════════╤═════════════════╤═══════════════╤════════════════════════════════╤════════════════════════════════╤════════════════════════════════╤═════════════╤════════════════╕\n");
    printf("│ Index │          Country               │   Demography   │          Capital               │  Continent    │   Vacancies     │ Test Covid-19 │             Tourism            │       Features of tourism      │              Sports            │ Flight Time │ Minimum Budget │ \n");
    printf("╞═══════╪════════════════════════════════╪════════════════╪════════════════════════════════╪═══════════════╪═════════════════╪═══════════════╪════════════════════════════════╪════════════════════════════════╪════════════════════════════════╪═════════════╪════════════════╡\n");

    for (int i = 0; i < st_len; i++)
    {
        printf("│ %5i │ %30s │ %14li │ %30s │ %13s │ %15s │ %13s │ %30s │ %30s │ %30s │ %7i min │ %12i $ │\n", key_data[i].id + 1, travel[key_data[i].id].travel.country,
               travel[key_data[i].id].travel.demography, travel[key_data[i].id].travel.capital,
               travel[key_data[i].id].travel.materic, travel[key_data[i].id].travel.is_required_vicinity ? "Required" : "Not Required",
               travel[key_data[i].id].travel.is_psr_test_required ? "Required" : "Not Required",
               travel[key_data[i].id].tourism.essential_type_of_tourism, travel[key_data[i].id].tourism.feature_of_tourism,
               travel[key_data[i].id].tourism.sports, travel[key_data[i].id].travel.time_of_way, travel[key_data[i].id].travel.min_budget);
        if (key_data[i].id != st_len - 1)
            printf("├───────┼────────────────────────────────┼────────────────┼────────────────────────────────┼───────────────┼─────────────────┼───────────────┼────────────────────────────────┼────────────────────────────────┼────────────────────────────────┼─────────────┼────────────────┤\n");
        else
            printf("└───────┴────────────────────────────────┴────────────────┴────────────────────────────────┴───────────────┴─────────────────┴───────────────┴────────────────────────────────┴────────────────────────────────┴────────────────────────────────┴─────────────┴────────────────┘\n");
    }
}


void st_print_table(st_travel *travel, int st_len)
{
    if (st_len == 0)
    {
        printf("\nTable is empty!\n");
        return;
    }

    printf("\n╒═══════╤════════════════════════════════╤════════════════╤════════════════════════════════╤═══════════════╤═════════════════╤═══════════════╤════════════════════════════════╤════════════════════════════════╤════════════════════════════════╤═════════════╤════════════════╕\n");
    printf("│ Index │          Country               │   Demography   │          Capital               │  Continent    │   Vacancies     │ Test Covid-19 │             Tourism            │       Features of tourism      │              Sports            │ Flight Time │ Minimum Budget │ \n");
    printf("╞═══════╪════════════════════════════════╪════════════════╪════════════════════════════════╪═══════════════╪═════════════════╪═══════════════╪════════════════════════════════╪════════════════════════════════╪════════════════════════════════╪═════════════╪════════════════╡\n");

    for (int i = 0; i < st_len; i++)
    {
        printf("│ %5i │ %30s │ %14li │ %30s │ %13s │ %15s │ %13s │ %30s │ %30s │ %30s │ %7i min │ %12i $ │\n", i + 1, travel[i].travel.country,
                travel[i].travel.demography, travel[i].travel.capital,
                travel[i].travel.materic, travel[i].travel.is_required_vicinity ? "Required" : "Not Required",
                travel[i].travel.is_psr_test_required ? "Required" : "Not Required",
                travel[i].tourism.essential_type_of_tourism, travel[i].tourism.feature_of_tourism,
                travel[i].tourism.sports, travel[i].travel.time_of_way, travel[i].travel.min_budget);
        if (i != st_len - 1)
            printf("├───────┼────────────────────────────────┼────────────────┼────────────────────────────────┼───────────────┼─────────────────┼───────────────┼────────────────────────────────┼────────────────────────────────┼────────────────────────────────┼─────────────┼────────────────┤\n");
        else
            printf("└───────┴────────────────────────────────┴────────────────┴────────────────────────────────┴───────────────┴─────────────────┴───────────────┴────────────────────────────────┴────────────────────────────────┴────────────────────────────────┴─────────────┴────────────────┘\n");
    }
}



void print_key_table (st_key *key, int rec_num)
{
    if (rec_num == 0)
    {
        printf("\nTable is empty!\n");
        return;
    }

    printf("\n╒═════════════╤═══════════╤═══════════════╕\n");
    printf("│ Table index │ Key index │ Minimal price │\n");
    printf("╞═════════════╪═══════════╪═══════════════╡\n");

    for (int i = 0; i < rec_num; i++)
    {
        printf("│ %11i │ %9i │ %13i │\n", i, key[i].id, key[i].count);

        if (i != rec_num-1)
            printf("├─────────────┼───────────┼───────────────┤\n");
        else
            printf("└─────────────┴───────────┴───────────────┘\n");
    }
}


#endif //LAB2_PRINT_FILE_H
