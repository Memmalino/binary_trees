#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root of the tree to measure the height
 * Return: void
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t rDepth, lDepth;

	if (tree == NULL)
		return (0);
	rDepth = binary_tree_height(tree->right);
	lDepth = binary_tree_height(tree->left);
	if (lDepth > rDepth)
		return (lDepth + 1);
	else
		return (rDepth + 1);
}
