#include "binary_trees.h"

/**
 * avl_height - Measures the height of an AVL tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int avl_height(const avl_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (0);

    left_height = avl_height(tree->left);
    right_height = avl_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * avl_balance - Calculates the balance factor of an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Balance factor of the AVL tree
 */
int avl_balance(const avl_t *tree)
{
    if (!tree)
        return (0);

    return (avl_height(tree->left) - avl_height(tree->right));
}

/**
 * avl_rotate_left - Performs a left-rotation on an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
avl_t *avl_rotate_left(avl_t *tree)
{
    avl_t *new_root;

    if (!tree || !tree->right)
        return (tree);

    new_root = tree->right;
    tree->right = new_root->left;
    if (new_root->left)
        new_root->left->parent = tree;
    new_root->left = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}

/**
 * avl_rotate_right - Performs a right-rotation on an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
avl_t *avl_rotate_right(avl_t *tree)
{
    avl_t *new_root;

    if (!tree || !tree->left)
        return (tree);

    new_root = tree->left;
    tree->left = new_root->right;
    if (new_root->right)
        new_root->right->parent = tree;
    new_root->right = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return (NULL);
        }
        else if (!root->left || !root->right)
        {
            avl_t *temp = root->left ? root->left : root->right;
            *root = *temp;
            free(temp);
        }
        else
        {
            avl_t *temp = root->right;
            while (temp->left)
                temp = temp->left;
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    int balance = avl_balance(root);
    if (balance > 1 && avl_balance(root->left) >= 0)
        return avl_rotate_right(root);
    if (balance > 1 && avl_balance(root->left) < 0)
    {
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    }
    if (balance < -1 && avl_balance(root->right) <= 0)
        return avl_rotate_left(root);
    if (balance < -1 && avl_balance(root->right) > 0)
    {
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }
    return root;
}
