#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"
#include "avl_tree.h"

//AVL tree node structure containing pointers to child nodes and parent, key, and associated data vector.
struct node {
    struct node* left_child;
    struct node* right_child;
    struct node* parent;
    MY_STRING key;
    GENERIC_VECTOR data;
};
typedef struct node Node;

//AVL tree structure holding a pointer to the root node.
struct avl_tree {
    Node *root ;
};
typedef struct avl_tree AVL_tree;

//Recursively destroys AVL tree nodes, freeing keys, data, and child nodes.
void destroy_node(Node *pNode);

//Recursively traverses AVL nodes to find the largest word family.
//Returns a pointer to the largest family vector in the tree.
//Uses blank-count tie-breaker when family sizes match.
//This is done to ensure most difficult path to victory for player.
//If enabled, prints the breakdown of the words remaining in the word list during traversal.
GENERIC_VECTOR find_max_family(Node *root, int running_total);

//Counts and returns the number of blanks in the given key string.
int count_blanks(MY_STRING key);

TREE avl_tree_init_default() {
    AVL_tree* pMy_tree = (AVL_tree*)malloc(sizeof(AVL_tree));
    if (pMy_tree != NULL) {
        pMy_tree->root = NULL;
    }
    return pMy_tree;
}

Status avl_tree_insert(TREE hMy_tree, MY_STRING key, MY_STRING item) {
    AVL_tree *pMy_tree = (AVL_tree*)hMy_tree;

    if (pMy_tree->root == NULL) {
        pMy_tree->root = (Node*) malloc(sizeof(Node));
        if (pMy_tree->root == NULL) {
            return FAILURE;
        }
        pMy_tree->root->left_child = NULL;
        pMy_tree->root->right_child = NULL;
        pMy_tree->root->parent = NULL;
        pMy_tree->root->key = my_string_init_c_string(my_string_c_str(key));
        pMy_tree->root->data = generic_vector_init_default(my_string_init_copy, my_string_destroy);

        generic_vector_push_back(pMy_tree->root->data, item);
        return SUCCESS;
    }

    int check = my_string_compare(pMy_tree->root->key, key);
    if (check > 0) {
        return avl_tree_insert(&(pMy_tree->root->right_child), key, item);
    }
    if (check < 0) {
        return avl_tree_insert(&(pMy_tree->root->left_child), key, item);
    }
    generic_vector_push_back(pMy_tree->root->data, item);
    return SUCCESS;
}

void avl_tree_destroy(TREE* phMy_tree) {
    AVL_tree *pMy_tree = (AVL_tree*)*phMy_tree;
    if (pMy_tree != NULL && pMy_tree->root != NULL) {
        destroy_node(pMy_tree->root);
    }
    free(pMy_tree);
    *phMy_tree = NULL;
}

GENERIC_VECTOR avl_tree_get_largest_family(TREE hMy_tree, int running_total) {
    AVL_tree *pMy_tree = (AVL_tree*)hMy_tree;

    GENERIC_VECTOR new_vector = generic_vector_init_default(my_string_init_copy, my_string_destroy);
    GENERIC_VECTOR temp = find_max_family(pMy_tree->root, running_total);
    if (temp == NULL) {
        return new_vector;
    }

    for (int i = 0; i < generic_vector_get_size(temp); i++) {
        generic_vector_push_back(new_vector, *generic_vector_at(temp, i));
    }
    return new_vector;
}

void destroy_node(Node *pNode) {
    if (pNode != NULL) {
        if (pNode->key != NULL) {
            my_string_destroy(&(pNode->key));
        }
        if (pNode->data != NULL) {
            generic_vector_destroy(&(pNode->data));
        }
        if (pNode->left_child != NULL) {
            destroy_node(pNode->left_child);
        }
        if (pNode->right_child != NULL) {
            destroy_node(pNode->right_child);
        }
        free(pNode);
    }
}

GENERIC_VECTOR find_max_family(Node *root, int running_total) {
    if (root == NULL) {
        return NULL;
    }

    GENERIC_VECTOR temp = root->data;

    if (root->left_child != NULL) {
        GENERIC_VECTOR left_max = find_max_family(root->left_child, running_total);
        if (left_max != NULL) {
            if (generic_vector_get_size(left_max) > generic_vector_get_size(temp)) {
                temp = left_max;
            } else if (generic_vector_get_size(left_max) == generic_vector_get_size(temp)) {
                if (count_blanks(root->left_child->key) > count_blanks(root->key)) {
                    temp = left_max;
                }
            }
        }
    }

    if (root->right_child != NULL) {
        GENERIC_VECTOR right_max = find_max_family(root->right_child, running_total);
        if (right_max != NULL) {
            if (generic_vector_get_size(right_max) > generic_vector_get_size(temp)) {
                temp = right_max;
            } else if (generic_vector_get_size(right_max) == generic_vector_get_size(temp)) {
                if (count_blanks(root->right_child->key) > count_blanks(root->key)) {
                    temp = right_max;
                }
            }
        }
    }

    if (running_total) {
        my_string_insertion(root->key, stdout);
        printf(" %d\n", generic_vector_get_size(root->data));
    }

    return temp;
}

int count_blanks(MY_STRING key) {
    int count = 0;
    char* word_key = my_string_c_str(key);
    for (int i = 0; i < my_string_get_size(key); i++) {
        if (word_key[i] == '-') {
            count++;
        }
    }
    return count;
}