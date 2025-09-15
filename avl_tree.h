#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "my_string.h"
#include "generic_vector.h"

// Define TREE as a handle to the AVL tree structure.
typedef void *TREE;

//Initializes an empty AVL tree.
//Returns: A TREE handle representing the new AVL tree.
TREE avl_tree_init_default(void);

//Inserts a key-item pair into the AVL tree.
//Initializes root if tree is empty, otherwise recursively finds insertion point.
//Adds item to existing key's vector if key matches.
//Returns SUCCESS on success, FAILURE if memory allocation fails.
Status avl_tree_insert(TREE hMy_tree, MY_STRING key, MY_STRING item);

//Recursively calls avl_tree_destroy_node until tree is empty.
//Sets the provided tree pointer to NULL after destruction.
void avl_tree_destroy(TREE *phMy_tree);

//Finds and returns a copy of the largest word family stored in the
//AVL tree using the avl_tree_find_max_family function
GENERIC_VECTOR avl_tree_get_largest_family(TREE hMy_tree, int running_total);

#endif