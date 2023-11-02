#include "binary_trees.h"

/**
 * binary_tree_balance - Calculate the tree balance
 * @tree: the pointer to the tree
 * Return: balance factor or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}


/**
 * binary_tree_height - calculate the height of a binary tree.
 * @tree: A pointer to the tree root node.
 * Return: height else 0 if tree is Null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
