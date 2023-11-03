#include "binary_trees.h"
#include <limits.h>
int is_bst_util(const binary_tree_t *node, int min, int max);
/**
 * is_bst_util - Helper function for binary_tree_is_bst
 * @node: Current node in traversal
 * @min: Minimum value for the node's value
 * @max: Maximum value for the node's value
 *
 * Return: 1 if the tree rooted at node is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_util(node->left, min, node->n) &&
			is_bst_util(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}

