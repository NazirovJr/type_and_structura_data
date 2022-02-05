//
// Created by nazirov on 04.12.2021.
//

#include "lib_tree_oper.h"

int comparator(const void *ft_elem, const void *sc_elem) {
    char *ft_str = (char *) ft_elem;
    char *sc_str = (char *) sc_elem;

    return strcmp(ft_str, sc_str);
}

st_node_branch *initialize_branch(st_node_branch *p_tree) {
    p_tree->right = NULL;
    p_tree->left = NULL;
    p_tree->height = 0;
    p_tree->key = NULL;

    return p_tree;
}

st_tree *create_tree(void) {
    st_tree *p_tree = calloc(1, sizeof(st_tree));
    p_tree->root = NULL;
    p_tree->size = 0;
    p_tree->total_compare = 0;
    return p_tree;
}

st_node_branch *create_node(char *key) {
    st_node_branch *new_node = malloc(sizeof(st_node_branch));
    new_node = initialize_branch(new_node);
    new_node->key = malloc((strlen(key) + 1) * sizeof(char));
    strcpy(new_node->key, key);
    new_node->height = 1;

    return new_node;
}

st_node_branch *find_node(st_node_branch *p_tree, char *key) {
    if (!p_tree)
        return NULL;

    int comp;
    while (p_tree) {
        comp = comparator(p_tree->key, key);
        if (comp == 0)
            return p_tree;
        else if (comp < 0)
            p_tree = p_tree->left;
        else
            p_tree = p_tree->right;
    }

    return NULL;
}

int height(st_node_branch *p) {
    return p ? p->height : 0;
}

int bfactor(st_node_branch *p) {
    if (height(p->right) == 1 && !p->left)
        return 2;
    else if (height(p->left) == 1 && !p->right)
        return -2;
    else
        return height(p->right) - height(p->left);
}

void fixheight(st_node_branch *p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

st_node_branch *rotateright(st_node_branch *p) {
    st_node_branch *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

st_node_branch *rotateleft(st_node_branch *q) {
    st_node_branch *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

st_node_branch *_balance(st_node_branch *p) {
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}


st_node_branch *remove_in_tree(char *rem, st_node_branch *tree, int *done, int *flag) {
    int cmp;

    if (tree == NULL)
        return tree;

    cmp = strcmp(rem, tree->key);
    if (!cmp) {
        *flag = 1;
        (*done)++;
        if (tree && !tree->left && !tree->right) {
            free(tree);
            fixheight(tree);
            return NULL;
        } else if (tree && !tree->left && tree->right) {
            st_node_branch *replace = tree->right;
            free(tree);
            fixheight(tree);
            return replace;
        } else if (tree && tree->left && !tree->right) {
            st_node_branch *replace = tree->left;
            free(tree);
            fixheight(tree);
            return replace;
        } else {
            st_node_branch *cur = tree->right;
            st_node_branch *prev_2 = tree;
            for (; cur->left; cur = cur->left)
                prev_2 = cur;
            //printf("\\ %s %s\n", cur->word, prev_2->word);

            if (tree == prev_2)
                prev_2->right = prev_2->right->right;
            else
                prev_2->left = NULL;
            //printf("\\ %s %s \n", cur->word, prev_2->word);

            cur->right = insert(cur->right, tree->right);
            cur->left = tree->left;
            st_node_branch *replace = cur;
            fixheight(tree);
            free(tree);
            return replace;

        }

    } else if (cmp < 0) {
        if (!*flag)
            (*done)++;
        tree->left = remove_in_tree(rem, tree->left, done, flag);
    } else if (cmp > 0) {
        if (!flag)
            (*done)++;
        tree->right = remove_in_tree(rem, tree->right, done, flag);
    }
    return tree;
}

void check_balance_in_del(st_node_branch *root) {
    fixheight(root);
    root = _balance(root);
}

st_node_branch *remove_in_bal_tree(char *rem, st_node_branch *tree, int *done, int *flag) {
    int cmp;

    if (tree == NULL)
        return tree;

    cmp = strcmp(rem, tree->key);
    if (!cmp) {
        *done = 1;
        if (tree && !tree->left && !tree->right) {
            free(tree);
            check_balance_in_del(tree);
            return NULL;
        } else if (tree && !tree->left && tree->right) {
            st_node_branch *replace = tree->right;
            free(tree);
            check_balance_in_del(tree);
            return replace;
        } else if (tree && tree->left && !tree->right) {
            st_node_branch *replace = tree->left;
            free(tree);
            check_balance_in_del(tree);
            return replace;
        } else {
            st_node_branch *cur = tree->left;
            st_node_branch *prev_2 = tree;
            for (; cur->right; cur = cur->right)
                prev_2 = cur;

            if (tree == prev_2)
                prev_2->left = prev_2->left->left;
            else
                prev_2->right = NULL;

            cur->left = insert(cur->left, tree->left);
            cur->right = tree->right;
            st_node_branch *replace = cur;
            check_balance_in_del(tree);
            free(tree);
            return replace;

        }

    } else if (cmp < 0)
        tree->left = remove_in_bal_tree(rem, tree->left, done, flag);

    else if (cmp > 0)
        tree->right = remove_in_bal_tree(rem, tree->right, done, flag);

    check_balance_in_del(tree);
    return tree;
}

st_node_branch *findmin(st_node_branch *p) // поиск узла с минимальным ключом в дереве p
{
    return p->left ? findmin(p->left) : p;
}

st_node_branch *removemin(st_node_branch *p) // удаление узла с минимальным ключом из дерева p
{
    if (p->left == 0)
        return p->right;
    p->left = removemin(p->left);
    return _balance(p);
}

st_node_branch *remove_t(st_node_branch *p, char *k, int *done, int *flag) // удаление ключа k из дерева p
{
    if (!p) return 0;
    int cmp = strcmp(k, p->key);
    if (cmp < 0) {
        if (!*flag)
            (*done)++;
        p->left = remove_t(p->left, k, done, flag);
    } else if (cmp > 0) {
        if (!*flag)
            (*done)++;
        p->right = remove_t(p->right, k, done, flag);
    } else {
        (*done)++;
        *flag = 1;
        st_node_branch *q = p->left;
        st_node_branch *r = p->right;
        p->left = NULL;
        p->right = NULL;
        if (!r) {
            return q;
        }
        st_node_branch *min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return _balance(min);
    }
    return _balance(p);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


st_node_branch *rightRotate(st_node_branch *y) {
    if (y->left) {
        st_node_branch *x = y->left;
        st_node_branch *temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }
    return NULL;
}


st_node_branch *leftRotate(st_node_branch *x) {
    if (x->right) {
        st_node_branch *y = x->right;
        st_node_branch *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    return NULL;
}

int getBalance(st_node_branch *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}


st_node_branch *insert(st_node_branch *node, char *key) {
    if (node == NULL)
        return (create_node(key));

    if (strcmp(key, node->key) > 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) < 0)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    st_node_branch *p = balance(node, key);
    if (p)
        return p;

    return node;
}

st_node_branch *insert_b(st_node_branch *node, char *key) {
    if (node == NULL)
        return (create_node(key));

    if (strcmp(key, node->key) > 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) < 0)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));


    return node;
}


st_node_branch *balance(st_node_branch *node, char *key) {
    int balance_el = getBalance(node);

    if (balance_el > 1 && strcmp(key, node->left->key) < 0)
        return rightRotate(node);

    if (balance_el < -1 && strcmp(key, node->right->key) > 0)
        return leftRotate(node);

    if (balance_el > 1 && strcmp(key, node->left->key) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance_el < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return NULL;
}