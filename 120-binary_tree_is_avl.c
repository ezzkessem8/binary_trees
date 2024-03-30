#include "binary_trees.h"

/**
 * max - finds the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: maximum of a and b
 */
static int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
static int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int lh, rh;

    if (tree == NULL)
        return (0);

    lh = height(tree->left);
    rh = height(tree->right);

    if (abs(lh - rh) <= 1 &&
        binary_tree_is_avl(tree->left) &&
        binary_tree_is_avl(tree->right))
        return (1);

    return (0);
}
