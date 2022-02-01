//
// Created by nazirov on 11.11.2021.
//

#include "../inc/timer.h"

void test_timer(){
    srand(time(NULL));

    time_t time_array, time_list;
    st_arr_que TestArray;
    st_list_que *TestList, listQue;
    TestList = &listQue;
    arr_que_init(&TestArray);
    list_que_init(&TestList);
    printf("----------------------------\n");
    printf("Time at clocks: \n");

    time_array = clock();
    for(int i = 0; i < MAX_SIZE_OF_QUE; i++)
        arr_que_push(&TestArray,1);
    time_array = clock() - time_array;
    printf("Array(Add elements): %ld\n", time_array);

    time_array = clock();
    for(int i = 0; i < MAX_SIZE_OF_QUE; i++)
        arr_que_pop(&TestArray);
    time_array = clock() - time_array;
    printf("Array(Pop elements): %ld\n", time_array);

    time_list = clock();
    for(int i = 0; i < MAX_SIZE_OF_QUE; i++)
        list_que_push(&TestList, 1);
    time_list = clock() - time_list;
    printf("List(Add elements): %ld\n", time_list);

    time_list = clock();
    for(int i = 0; i < MAX_SIZE_OF_QUE; i++)
        list_que_pop(&TestList);
    time_list = clock() - time_list;
    printf("List(Pop elements): %ld\n", time_list);

    free(TestArray.arr);
//       printf("----------------------------\n");
//       printf("Time at clocks: \n");
//       printf("Array: %ld\n", time_array);
//       printf("List: %ld\n", time_list);
}