#include "binary_trees.h"

/**
 * binary_tree_depth - Count binary tree depth
 * @tree: the pointer to the tree
 * Return: number of nodes and 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_count = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		depth_count += 1;
		tree = tree->parent;
	}
	return (depth_count);
}
