#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that\\
 * insert node to the left of a binary tree
 * @parent: the pointer to the parent of the binary tree
 * @value: the value to be inserted to the left
 * Return: pointer to the created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	tmp = binary_tree_node(parent, value);
	if (tmp == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		tmp->left = parent->left;
		parent->left->parent = tmp;

	}
	parent->left = tmp;
	return (tmp);
}
