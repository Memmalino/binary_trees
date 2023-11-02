#include "binary_trees.h"
/**
 * binary_tree_is_full - a function that Check if binary tree is full
 * @tree: a pointer to the node
 * Return: 1 if full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (recursive_check(tree));
}
/**
 * recursive_check - a function that check if full recurisively
 * @tree: pointer to the node
 * Return: 1 if full 0 otherwise
 */
int recursive_check(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    recursive_check(tree->left) == 0 ||
		    recursive_check(tree->right) == 0)
			return (0);
	}
	return (1);
}
