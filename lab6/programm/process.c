#include "process.h"



void process(void) {
    printf("\n\n\nWelcome to program");
    char file_name[FILENAME_MAX];
    do {
        printf("\nPlease enter the correct file name: ");
        scanf("%s", file_name);
    } while (check_file(file_name) != EXIT_SUCCESS);
    FILE *file = fopen(file_name, "r");
    int hash_table_size = 0, flag_hs, amount_of_compare = 0;
    do {
        printf("\n-- 0 -- Enter by yourself the sizeof hash table");
        printf("\n-- 1 -- Program should count the size of hash table");
        printf("\nPlease enter your choice: ");
    } while (scanf("%d", &flag_hs) != 1 || flag_hs != 1 && flag_hs != 0);

    if (!flag_hs) {
        do {
            printf("\nPlease enter the size of hash table: ");
        } while (scanf("%d", &hash_table_size) != 1);
    }
    else
        hash_table_size = get_size(file);

    do {
        printf("\nPlease enter the amount of compare in hash table: ");
    } while (scanf("%d", &amount_of_compare) != 1);


    st_tree *avl_tree = create_tree(), *b_tree = create_tree();
    st_hash_table *hashTable = malloc(sizeof(st_hash_table));
    init_hash_table(hash_table_size, hashTable);
    read_file(file, &avl_tree, &b_tree, &hashTable, 100);
    print_tree(*avl_tree, 1);
    print_tree(*b_tree, 0);

    int choice = 1, flag = 0, done = 0;
    while (choice)
    {
        printf("\n\n-- 1 -- Add binary tree");
        printf("\n-- 2 -- Add Avl tree");
        printf("\n-- 3 -- add hash table");
        printf("\n-- 4 -- remove binary tree");
        printf("\n-- 5 -- remove Avl tree");
        printf("\n-- 6 -- remove hash table");
        printf("\n-- 7 -- print binary tree");
        printf("\n-- 8 -- print Avl tree");
        printf("\n-- 9 -- print hash table");
        do {
            printf("\nPlease enter your choice: ");
        } while (scanf("%d", &choice) != 1 && choice >= 0 && choice <= 9);

        char str[100];
        switch (choice) {
            case 1:
            {
                do {
                    printf("\nPlease enter word: ");
                } while (scanf("%s", str) != 1);
                b_tree->root = insert_b(b_tree->root, str);
                break;
            }
            case 2:{
                do {
                    printf("\nPlease enter word: ");
                } while (scanf("%s", str) != 1);
                avl_tree->root = insert(avl_tree->root, str);
                break;
            }
            case 3: {
                do {
                    printf("\nPlease enter word: ");
                } while (scanf("%s", str) != 1);
                insertion_to_table(hashTable, str);
                break;
            }
            case 4:{
                do {
                    printf("\nPlease enter word: ");
                } while (scanf("%s", str) != 1);
                st_node_branch *res = remove_in_tree(str, b_tree->root, &done, &flag);
                if (!res)
                    printf("File not found");
                else
                    b_tree->root = res;
                break;
            }
            case 5: {
                do {
                    printf("\nPlease enter word: ");
                } while (scanf("%s", str) != 1);
                st_node_branch *res = remove_in_bal_tree(str, avl_tree->root, &done, &flag);
                if (!res)
                    printf("File not found");
                else
                    avl_tree->root = res;
                break;
            }
            case 6: {
                break;
            }
            case 7:{
                print_tree(*b_tree, 0);
                break;
            }
            case 8: {
                print_tree(*avl_tree, 1);
                break;
            }
            case 9:{
                print_hash_table(*hashTable);
                break;
            }



        }
    }



}


