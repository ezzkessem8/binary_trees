#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete - Checks if a binary tree is complete recursively
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, size) &&
            is_complete(tree->right, 2 * index + 2, size));
}
