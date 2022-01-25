//
// Created by nazirov on 05.10.2021.
//

#ifndef LAB2_UTILS_H
#define LAB2_UTILS_H

#include <stdio.h>
#define LEN_OF_COUNTRY 20
#define LEN_OF_CAPITAL 20
#define LEN_OF_MATERIC 20
#define LEN_OF_TOURISM 20
#define LEN_OF_SPORT 20
#define AMOUNT_OF_SPORT 20
#define LEN_OF_FEATURE 100
#define MAX_LENGTH_OF_STRUCT 2000
#define MAX_LENGTH_OF_STRING 100
#define THIRTEEN 13
#define ERROR_FILE -5
#define ERROR_CONSOLE_INPUT -10
#define ARG_ERROR -7
#define TABLE_OVER_FLOW -3
#define ONE 1
#define FIFE 5
#define FILE_NAME "data.csv"

static char continent[FIFE][FIFE * 2] = {"Asia", "Europe", "America", "Australia", "Africa"};

typedef struct {
    int id;
    int count;
} st_key;

typedef struct {
    char essential_type_of_tourism[LEN_OF_TOURISM];
    char feature_of_tourism[LEN_OF_FEATURE];
    char sports[LEN_OF_SPORT * AMOUNT_OF_SPORT];
} st_tourism;

typedef struct {
    char country[LEN_OF_COUNTRY];
    char capital[LEN_OF_CAPITAL];
    char materic[LEN_OF_MATERIC];
    long int demography;
    int min_budget;
    int time_of_way;
    short is_required_vicinity;
    short is_psr_test_required;
} travel_data;

typedef struct {
    travel_data travel;
    st_tourism tourism;
} st_travel;

typedef union {
    st_travel travel_data;
    st_tourism tourism;
} travel_union;

#endif //LAB2_UTILS_H
