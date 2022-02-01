//
// Created by nazirov on 09.11.2021.
//

#include "../inc/list_que_operation.h"

void list_que_init(st_list_que **list_que)
{
    (*list_que)->size = 0;
    (*list_que)->head = (*list_que)->tail = NULL;
}

double list_que_push(st_list_que **list_que, double value)
{
    if ((*list_que)->size > MAX_SIZE_OF_QUE)
        return QUE_OVERFLOW;

    node *new_element = malloc(sizeof(node));
    int rc = new_element != NULL ? EXIT_SUCCESS : MEMORY_ERROR;
    if (rc == EXIT_SUCCESS) {
        new_element->next = NULL;
        new_element->data = value;
        if ((*list_que)->size) {
            (*list_que)->tail->next = new_element;
            (*list_que)->tail = new_element;
        } else
            (*list_que)->tail = (*list_que)->head = new_element;

        (*list_que)->size++;
    }


    return value;
}

double list_que_pop(st_list_que **list_que)
{
    if ((*list_que)->size < 1)
        return EMPTY_QUE;

    double removed_element;
    node *temp = (*list_que)->head;

    (*list_que)->head = (*list_que)->head->next;
    (*list_que)->size --;

    removed_element = temp->data;
    temp->data = 0;
    temp->next = NULL;

    free(temp);

    return removed_element;
}

void clear_list_que(st_list_que **list_que)
{
    while ((*list_que)->size <= 0)
        list_que_pop(list_que);

    (*list_que)->size = 0;
    (*list_que)->head = (*list_que)->tail = NULL;
}