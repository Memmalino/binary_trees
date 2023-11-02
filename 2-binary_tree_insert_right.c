#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that insert node to \\
 * the right of a binary tree
 * @parent: pointer to the node to insert the right child
 * @value: is the value to store in the new node
 * Return: NULL on failure or if parent is NULL\\
 * else pointer to the created node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	tmp = binary_tree_node(parent, value);
	if (tmp == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		tmp->right = parent->right;
		parent->right->parent = tmp;
	}
	parent->right = tmp;
	return (tmp);
}
