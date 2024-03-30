#include "binary_trees.h"

/**
 * find_last_node - Finds the last node in the heap
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root)
{
    if (root == NULL)
        return (NULL);

    queue_t *queue = NULL;
    heap_t *current = NULL;

    queue = queue_push(queue, root);

    while (queue != NULL)
    {
        current = queue_pop(&queue);

        if (current->left != NULL)
            queue = queue_push(queue, current->left);
        if (current->right != NULL)
            queue = queue_push(queue, current->right);
    }

    return (current);
}

/**
 * heapify_down - Rebuilds the heap downward
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = NULL;
    int temp;

    while (1)
    {
        largest = root;

        if (root->left != NULL && root->left->n > largest->n)
            largest = root->left;

        if (root->right != NULL && root->right->n > largest->n)
            largest = root->right;

        if (largest == root)
            break;

        temp = root->n;
        root->n = largest->n;
        largest->n = temp;

        root = largest;
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return (0);

    int value = (*root)->n;
    heap_t *last_node = find_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    heapify_down(*root);

    return (value);
}
