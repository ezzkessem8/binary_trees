#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the binary tree
 * @index: The index of the current node
 * @count: The number of nodes in the binary tree
 * Return: 1 if the binary tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree, int index, int count)
{
    if (tree == NULL)
        return (1);

    if (index >= count)
        return (0);

    return (binary_tree_is_complete(tree->left, 2 * index + 1, count) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 * Return: 1 if the binary tree is a valid Max Binary Heap, otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!binary_tree_is_complete(tree, 0, binary_tree_size(tree)))
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) &&
            binary_tree_is_heap(tree->right));
}
