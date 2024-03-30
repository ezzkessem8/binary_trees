#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    queue<heap_t *> q;
    q.push(*root);
    while (!q.empty())
    {
        heap_t *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = binary_tree_node(temp, value);
            return temp->left;
        }
        else if (temp->right == NULL)
        {
            temp->right = binary_tree_node(temp, value);
            return temp->right;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return NULL;
}
