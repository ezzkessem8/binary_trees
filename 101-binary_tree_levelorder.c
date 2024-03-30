#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;

    if (tree == NULL || func == NULL)
        return;

    enqueue(&queue, (binary_tree_t *)tree);

    while (!is_empty(queue))
    {
        binary_tree_t *node = dequeue(&queue);

        func(node->n);

        if (node->left)
            enqueue(&queue, node->left);
        if (node->right)
            enqueue(&queue, node->right);
    }

    free_queue(queue);
}
