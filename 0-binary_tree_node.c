#include "binary_trees.h"
/**
 * binary_tree_node - function that create a new binary tree
 * @parent: the pointer to parent node to create new binary tree
 * @value: the value of the node n
 * Return: ponter to the new created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp = malloc(sizeof(binary_tree_t));

	if (tmp == NULL)
		return (NULL);
	tmp->n = value;
	tmp->parent = parent;
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}


