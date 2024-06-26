#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *ancestor;

    if (first == NULL || second == NULL)
        return (NULL);

    ancestor = first;
    while (ancestor != NULL)
    {
        if (binary_tree_is_ancestor(ancestor, second))
            return ((binary_tree_t *)ancestor);
        ancestor = ancestor->parent;
    }

    return (NULL);
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node
 * @ancestor: Pointer to the node to check if it's an ancestor
 * @node: Pointer to the node to check if it's a descendant
 *
 * Return: 1 if ancestor is an ancestor of node, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
    while (node != NULL)
    {
        if (node == ancestor)
            return (1);
        node = node->parent;
    }
    return (0);
}
