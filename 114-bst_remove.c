#include "binary_trees.h"
bst_t *find_min_value(bst_t *node);
/**
 * find_min_value - Finds the minimum value node in a BST
 * @node: A pointer to the root node of the subtree
 *
 * Return: A pointer to the node with the minimum value
 */
bst_t *find_min_value(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: A pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = find_min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

