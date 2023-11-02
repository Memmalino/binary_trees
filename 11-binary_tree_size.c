#include "binary_trees.h"

/**
 * binary_tree_size - A functioncomputes the size of a binary tree
 * @root: pointer to the root node of the tree
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *root)
{
    size_t tree_size = 0;

    if (root)
    {
        tree_size += 1;
        tree_size += binary_tree_size(root->left);
        tree_size += binary_tree_size(root->right);
    }

    return (tree_size);
}
