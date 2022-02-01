//
// Created by nazirov on 23.10.2021.
//

#ifndef LAB4_STACK_STRUCT_H
#define LAB4_STACK_STRUCT_H
enum ZNAK {PLUS = 1, MINUS = -1/*, MULTIPLY, DIVIDE*/};

typedef struct node_el {
    int number;
    int obelus;
    struct node_el *prev;

} node;


typedef struct {
    node *ptr;
} stack_list;

typedef struct {
    int **arr_stack;
    int top_size;
    int size;
} stack_array;


#endif //LAB4_STACK_STRUCT_H
