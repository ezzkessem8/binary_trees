#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return NULL;

    /* Find middle element */
    size_t mid = size / 2;

    /* Create root node */
    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return NULL;

    /* Recursively build left and right subtrees */
    root->left = sorted_array_to_avl(array, mid);
    root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

    return root;
}
