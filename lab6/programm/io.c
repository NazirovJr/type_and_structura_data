#include "io.h"

int _height = 1;

int read_file(FILE *f, st_tree **avl_tree, st_tree **b_tree, st_hash_table **p_hash_table, int len_c) {
    char *temp = malloc(len_c * sizeof(node_el));
    int rc = EXIT_SUCCESS;

    int height = 0;
    while ((rc = fscanf(f, "%s", temp)) == 1) {
        height = -1;
        (*b_tree)->root = insert_b((*b_tree)->root, temp);
        height = -1;
        insert_hash_table(p_hash_table, temp);
        (*avl_tree)->root = insert((*avl_tree)->root, temp);
        insertion_to_table(*p_hash_table, temp);
    }

    if (rc == -1)
        rc = ERR_IO;
    else
        rc = EXIT_FAILURE;

    free(temp);
    return rc;
}


int get_size(FILE *f) {
    int len = 0;
    char s[BUF_SIZE + 1];
    if (f == NULL)
        len = FILE_ERR;
    else
        while (fgets(s, BUF_SIZE, f) != NULL && s[0] != '\000')
            len++;


    rewind(f);
    return len;
}


static void prepare_data_for_print(const struct node_branch *const root, char *buffer) {
    if (root->right == NULL && root->left == NULL) {
        return;
    }

    char str_height[MAX_HEIGHT_SIZE];

    strcat(buffer, root->key);
    buffer[strlen(buffer)] = ' ';

    root->left == NULL || root->left->key == NULL ? strcat(buffer, "NULL") : strcat(buffer, root->left->key);
    buffer[strlen(buffer)] = ' ';

    root->right == NULL || root->right->key == NULL ? strcat(buffer, "NULL") : strcat(buffer, root->right->key);
    buffer[strlen(buffer)] = ' ';

    sprintf(str_height, "%d", root->height);
    strcat(buffer, str_height);
    buffer[strlen(buffer)] = '_';

    if (root->right != NULL) {
        prepare_data_for_print(root->right, buffer);
    }

    if (root->left != NULL) {
        prepare_data_for_print(root->left, buffer);
    }
}

static void calculate_height(st_node_branch *vertex)
{
    if (vertex->right == NULL && vertex->left == NULL)
    {
        _height = 1;
    }

    if (vertex->left != NULL)
    {
        vertex->left->height = _height;
    }

    if (vertex->right != NULL)
    {
        vertex->right->height = _height;
    }

    if (vertex->right != NULL)
    {
        ++_height;
        calculate_height(vertex->right);
    }

    if (vertex->left != NULL)
    {
        ++_height;
        calculate_height(vertex->left);
    }
}


void print_tree(st_tree tree, bool is_balanced) {
    char buffer[N] = "python3 ../painting.py '";

    if (is_balanced) {
        _height = 1;
        tree.root->height = 0;
        calculate_height(tree.root);
    }

    prepare_data_for_print(tree.root, buffer);
    buffer[strlen(buffer) - 1] = ASCII_APOSTROPHE;
    system(buffer);
}

void print_hash_table(st_hash_table table) {
    fprintf(stdout, "%s", "\n======= ХЕШ-ТАБЛИЦА ======="
                          "\nЯчейки без значения НЕ БУДУТ выведены на экран\n");

    fprintf(stdout, "Среднее количество сравнений для %d элементов хеш-таблицы: %lf\n",
            table.size, (double) table.total_compare);

    for (int i = 0; i < table.size; i++) {
        if (table.ptr[i].string != NULL) {
            printf("\nКЛЮЧ: %d | Значение: %s", i, table.ptr[i].string);


            node_el *temp = table.ptr[i].next;
            while (temp != NULL) {
                if (temp->string != NULL)
                    printf(" -> Значение: %s", temp->string);
                temp = temp->next;
            }

        }
    }

    putchar('\n');
}



