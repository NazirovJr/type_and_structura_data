//
// Created by nazirov on 12.11.2021.
//

#include "../inc/process.h"
#include "../inc/que_struct.h"
#include "../inc/utils.h"
#include "../inc/menu.h"
#include "../inc/arr_que_operation.h"
#include "../inc/list_que_operation.h"
#include <time.h>

void arr_que_model(void) {
    srand(time(NULL));
    int ll = 0, show = 0;

    double t1_start = T1_START, t1_end = T1_END, t2_start = T2_START, t2_end = T2_END;
    double t3_start = T3_START, t3_end = T3_END, t4_start = T4_START, t4_end = T4_END;


    int first_finish = 0, second_finish = 0, second_thrown = 0;
    double first_time = 0, second_time = 0, time_line_res = 0, not_worked_time = 0;

    double first_enter = 0, ft_work = 0, second_enter = 0, second_work = 0;
    double time_ft = 0, time_sc = 0;
    int ft_cur = 0, sc_cur = 0, iteration = 0, iter_sc = 0;
    int ft_cur_sum = 0, sc_cur_sum = 0, sc_in_work = 0;


    st_arr_que ft_arr_que, sc_arr_que;
    arr_que_init(&ft_arr_que);
    arr_que_init(&sc_arr_que);

    printf("\nDo you want to see added and deleted element: ");
    printf("\n--- 1 --> Yes");
    printf("\n--- 0 --> No");
    printf("\nPlease enter your choice: ");
    while (scanf("%d", &show) != 1 || show != 0 && show != 1) {
        clean_buffer();
        printf("\nPlease enter your choice correctly: ");
    }

    menu_change("First", &t1_start, &t1_end);
    menu_change("Second", &t2_start, &t2_end);
    menu_change("Third", &t3_start, &t3_end);
    menu_change("Fourth", &t4_start, &t4_end);

    while (first_finish < MAX_SIZE_OF_QUE) {
        iteration++;

        while ((time_line_res > first_time) || (ft_arr_que.size == 0)) {
            first_enter = t1_start + (t1_end - t1_start) * ((double) rand() / (double) RAND_MAX);
            if (show)
                printf("FirstIn = %lf FirstDone = %d\n", first_enter, first_finish);
            first_time += first_enter;
            arr_que_push(&ft_arr_que, first_time);
        }

        while ((time_line_res > second_time) || (sc_arr_que.size == 0)) {
            second_enter = t2_start + (t2_end - t2_start)*((double) rand() / (double) RAND_MAX);
            if (show)
                printf("SecondtIn = %lf second_finish = %d\n", second_enter, second_finish);
            second_time += second_enter;
            iter_sc ++;
            arr_que_push(&sc_arr_que, second_time);
        }

        ft_cur = ft_arr_que.size;
        sc_cur = sc_arr_que.size;
        ft_cur_sum += ft_cur;
        sc_cur_sum += sc_cur;

        if (ft_cur >= MAX_SIZE || sc_cur >= MAX_SIZE) {
            printf("\nOVERFLOW!");
            print__que_info(time_line_res, not_worked_time, first_finish + ft_arr_que.size, first_finish,
                            second_finish + sc_arr_que.size, second_finish, second_thrown, time_ft / first_finish,
                            time_sc / sc_in_work, fabs(100 * (time_line_res - first_finish * (t1_start + t1_end) / 2) /
                                                       (first_finish * (t1_start + t1_end) / 2)));
            return;
        }

        if ((ft_arr_que.arr[0] <= time_line_res) || (ft_arr_que.arr[0] <= sc_arr_que.arr[0])) {

            if (ft_arr_que.arr[0] > time_line_res) {
                not_worked_time += ft_arr_que.arr[0] - time_line_res;
                time_line_res += ft_arr_que.arr[0] - time_line_res;
            }

            ft_work = t3_start + (t3_end - t3_start) * ((double) rand() / (double) RAND_MAX);
            time_line_res += ft_work;
            time_ft += time_line_res - arr_que_pop(&ft_arr_que);
            first_finish++;
            if (first_finish % 100 == 0) {
                print_timing_result(first_finish, ft_cur - 1, (ft_cur_sum - 1) / (double) iteration, sc_cur,
                                sc_cur_sum / (double) iteration, time_ft / first_finish,
                                time_sc / (second_finish + second_thrown));
            }
        } else {
            sc_in_work++;
            second_work = t4_start + (t4_end - t4_start) * ((double) rand() / (double) RAND_MAX);
            ll++;
            if (sc_arr_que.arr[0] > time_line_res) {
                not_worked_time += sc_arr_que.arr[0] - time_line_res;
                time_line_res += sc_arr_que.arr[0] - time_line_res;
            }

            if (ft_arr_que.arr[0] >= time_line_res + second_work) {
                time_line_res += second_work;
                time_sc += time_line_res - arr_que_pop(&sc_arr_que);
                second_finish++;
            } else {
                time_sc += time_line_res - arr_que_pop(&sc_arr_que);
                time_line_res = ft_arr_que.arr[0];
                second_thrown++;
                arr_que_push(&sc_arr_que, time_line_res);
            }
        }
    }
  //  printf("%d", ll);
    print__que_info(time_line_res, not_worked_time, first_finish + ft_arr_que.size, first_finish,
                    second_finish + sc_arr_que.size, second_finish, second_thrown, time_ft / first_finish,
                    time_sc / sc_in_work, fabs(100 * (time_line_res - first_finish * (t1_start + t1_end) / 2) /
                                               (first_finish * (t1_start + t1_end) / 2)));
    arr_que_clear(&ft_arr_que);
    arr_que_clear(&sc_arr_que);
    free(ft_arr_que.arr);
    free(sc_arr_que.arr);
    print_theory(not_worked_time, time_line_res, first_finish + ft_arr_que.size, second_finish + sc_arr_que.size, (int) t1_start, (int) t1_end,
                 (int) t2_start, (int) t2_end, (int) t3_start, (int) t3_end, (int) t4_start, (int) t4_end);
}


void list_que_model(void) {
    srand(time(NULL));
    int ll = 0, show = 0;

    double t1_start = T1_START, t1_end = T1_END, t2_start = T2_START, t2_end = T2_END;
    double t3_start = T3_START, t3_end = T3_END, t4_start = T4_START, t4_end = T4_END;


    int first_finish = 0, second_finish = 0, second_thrown = 0;
    double first_time = 0, second_time = 0, time_line_res = 0, not_worked_time = 0;

    double first_enter = 0, ft_work = 0, second_enter = 0, second_work = 0;
    double time_ft = 0, time_sc = 0;
    int ft_cur = 0, sc_cur = 0, iteration = 0, iter_sc = 0;
    int ft_cur_sum = 0, sc_cur_sum = 0, sc_in_work = 0;


    st_list_que *ft_list_que, *sc_list_que, first_list, second_list;
    ft_list_que = &first_list;
    sc_list_que = &second_list;
    list_que_init(&ft_list_que);
    list_que_init(&sc_list_que);


    printf("\nDo you want to see added and deleted element: ");
    printf("\n--- 1 --> Yes");
    printf("\n--- 0 --> No");
    printf("\nPlease enter your choice: ");
    while (scanf("%d", &show) != 1 || show != 0 && show != 1) {
        clean_buffer();
        printf("\nPlease enter your choice correctly: ");
    }

    menu_change("First", &t1_start, &t1_end);
    menu_change("Second", &t2_start, &t2_end);
    menu_change("Third", &t3_start, &t3_end);
    menu_change("Fourth", &t4_start, &t4_end);

    while (first_finish < MAX_SIZE_OF_QUE) {
        iteration++;

        while ((time_line_res > first_time) || ((*ft_list_que).size == 0)) {
            first_enter = t1_start + (t1_end - t1_start) * ((double) rand() / (double) RAND_MAX);
            if (show)
                printf("FirstIn = %lf FirstDone = %d\n", first_enter, first_finish);
            first_time += first_enter;
            list_que_push(&ft_list_que, first_time);
        }

        while ((time_line_res > second_time) || ((*sc_list_que).size == 0)) {
            second_enter = t2_start + (t2_end - t2_start)*((double) rand() / (double) RAND_MAX);
            if (show)
                printf("SecondtIn = %lf second_finish = %d\n", second_enter, second_finish);
            second_time += second_enter;
            iter_sc ++;
            list_que_push(&sc_list_que, second_time);
        }

        ft_cur = (*ft_list_que).size;
        sc_cur = (*sc_list_que).size;
        ft_cur_sum += ft_cur;
        sc_cur_sum += sc_cur;

        if (ft_cur >= MAX_SIZE || sc_cur >= MAX_SIZE) {
            printf("\nOVERFLOW!");
            print__que_info(time_line_res, not_worked_time, first_finish + (*ft_list_que).size, first_finish,
                            second_finish + (*sc_list_que).size, second_finish, second_thrown, time_ft / first_finish,
                            time_sc / sc_in_work, fabs(100 * (time_line_res - first_finish * (t1_start + t1_end) / 2) /
                                                       (first_finish * (t1_start + t1_end) / 2)));
            return;
        }

        if (((*ft_list_que).head->data <= time_line_res) || ((*ft_list_que).head->data <= (*sc_list_que).head->data)) {

            if ((*ft_list_que).head->data > time_line_res) {
                not_worked_time += (*ft_list_que).head->data - time_line_res;
                time_line_res += (*ft_list_que).head->data - time_line_res;
            }

            ft_work = t3_start + (t3_end - t3_start) * ((double) rand() / (double) RAND_MAX);
            time_line_res += ft_work;
            time_ft += time_line_res - list_que_pop(&ft_list_que);
            first_finish++;
            if (first_finish % 100 == 0) {
                print_timing_result(first_finish, ft_cur - 1, (ft_cur_sum - 1) / (double) iteration, sc_cur,
                                    sc_cur_sum / (double) iteration, time_ft / first_finish,
                                    time_sc / (second_finish + second_thrown));
            }
        } else {
            sc_in_work++;
            second_work = t4_start + (t4_end - t4_start) * ((double) rand() / (double) RAND_MAX);
            ll++;
            if ((*sc_list_que).head->data > time_line_res) {
                not_worked_time += (*sc_list_que).head->data - time_line_res;
                time_line_res += (*sc_list_que).head->data - time_line_res;
            }

            if ((*ft_list_que).head->data >= time_line_res + second_work) {
                time_line_res += second_work;
                time_sc += time_line_res - list_que_pop(&sc_list_que);
                second_finish++;
            } else {
                time_sc += time_line_res - list_que_pop(&sc_list_que);
                time_line_res = (*ft_list_que).head->data;
                second_thrown++;
                list_que_push(&sc_list_que, time_line_res);
            }
        }
    }
    printf("\nSecond %d", iter_sc);
    print__que_info(time_line_res, not_worked_time, first_finish + (*ft_list_que).size, first_finish,
                    second_finish + (*sc_list_que).size, second_finish, second_thrown, time_ft / first_finish,
                    time_sc / sc_in_work, fabs(100 * (time_line_res - first_finish * (t1_start + t1_end) / 2) /
                                               (first_finish * (t1_start + t1_end) / 2)));
    print_theory(not_worked_time, time_line_res,  first_enter, (int) second_enter, (int) t1_start, (int) t1_end,
                 (int) t2_start, (int) t2_end, (int) t3_start, (int) t3_end, (int) t4_start, (int) t4_end);
//    clear_list_que(&ft_list_que);
//    clear_list_que(&sc_list_que);
}


void fragmentation_que_model(void) {
    srand(time(NULL));
    int ll = 0, show = 0;

    double t1_start = T1_START, t1_end = T1_END, t2_start = T2_START, t2_end = T2_END;
    double t3_start = T3_START, t3_end = T3_END, t4_start = T4_START, t4_end = T4_END;


    int first_finish = 0, second_finish = 0, second_thrown = 0;
    double first_time = 0, second_time = 0, time_line_res = 0, not_worked_time = 0;

    double first_enter = 0, ft_work = 0, second_enter = 0, second_work = 0;
    double time_ft = 0, time_sc = 0;
    int ft_cur = 0, sc_cur = 0, iteration = 0, iter_sc = 0;
    int ft_cur_sum = 0, sc_cur_sum = 0, sc_in_work = 0;


    st_list_que *ft_list_que, *sc_list_que, first_list, second_list;
    ft_list_que = &first_list;
    sc_list_que = &second_list;
    list_que_init(&ft_list_que);
    list_que_init(&sc_list_que);


    while (first_finish < MAX_SIZE_OF_QUE) {
        iteration++;

        while ((time_line_res > first_time) || ((*ft_list_que).size == 0)) {
            first_enter = t1_start + (t1_end - t1_start) * ((double) rand() / (double) RAND_MAX);
            first_time += first_enter;
            list_que_push(&ft_list_que, first_time);
            printf("\n%p", ft_list_que->head);
        }

        while ((time_line_res > second_time) || ((*sc_list_que).size == 0)) {
            second_enter = t2_start + (t2_end - t2_start)*((double) rand() / (double) RAND_MAX);
            second_time += second_enter;
            list_que_push(&sc_list_que, second_time);
            printf("\n%p", sc_list_que->head);
        }

        ft_cur = (*ft_list_que).size;
        sc_cur = (*sc_list_que).size;
        ft_cur_sum += ft_cur;
        sc_cur_sum += sc_cur;

        if (ft_cur >= MAX_SIZE || sc_cur >= MAX_SIZE) {
            printf("\nOVERFLOW!");
            return;
        }

        if (((*ft_list_que).head->data <= time_line_res) || ((*ft_list_que).head->data <= (*sc_list_que).head->data)) {

            if ((*ft_list_que).head->data > time_line_res) {
                not_worked_time += (*ft_list_que).head->data - time_line_res;
                time_line_res += (*ft_list_que).head->data - time_line_res;
            }

            ft_work = t3_start + (t3_end - t3_start) * ((double) rand() / (double) RAND_MAX);
            time_line_res += ft_work;
            time_ft += time_line_res - list_que_pop(&ft_list_que);
            first_finish++;
        } else {
            sc_in_work++;
            second_work = t4_start + (t4_end - t4_start) * ((double) rand() / (double) RAND_MAX);
            ll++;
            if ((*sc_list_que).head->data > time_line_res) {
                not_worked_time += (*sc_list_que).head->data - time_line_res;
                time_line_res += (*sc_list_que).head->data - time_line_res;
            }

            if ((*ft_list_que).head->data >= time_line_res + second_work) {
                time_line_res += second_work;
                time_sc += time_line_res - list_que_pop(&sc_list_que);
                second_finish++;
            } else {
                time_sc += time_line_res - list_que_pop(&sc_list_que);
                time_line_res = (*ft_list_que).head->data;
                second_thrown++;
                list_que_push(&sc_list_que, time_line_res);
            }
        }
    }
//    clear_list_que(&ft_list_que);
//    clear_list_que(&sc_list_que);
}