#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree Structure */
typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree Structure */
typedef struct binary_tree_s bst_t;

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap Structure */
typedef struct binary_tree_s heap_t;

/* Binary Tree Node Structure */
struct binary_tree_s
{
    int n; /* Node value */
    struct binary_tree_s *parent; /* Pointer to the parent node */
    struct binary_tree_s *left; /* Pointer to the left child node */
    struct binary_tree_s *right; /* Pointer to the right child node */
};

/* Function Prototypes */

/* Task 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3 */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4 */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Task 5 */
int binary_tree_is_root(const binary_tree_t *node);

/* Task 6 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Task 7 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Task 8 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Task 9 */
size_t binary_tree_height(const binary_tree_t *tree);

/* Task 10 */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Task 11 */
size_t binary_tree_size(const binary_tree_t *tree);

/* Task 12 */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Task 13 */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Task 14 */
int binary_tree_balance(const binary_tree_t *tree);

/* Task 15 */
int binary_tree_is_full(const binary_tree_t *tree);

/* Task 16 */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Task 17 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Task 18 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Task 19 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* Task 20 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Task 21 */
int binary_tree_is_complete(const binary_tree_t *tree);

/* Task 22 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* Task 23 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

#endif /* BINARY_TREES_H */
