#include "binary_trees.h"
/**
 * binary_trees_ancestor - function that locate the lowest minimum ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: the pointer to the L.M.A
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *node_a, *node_b;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	node_a = first->parent;
	node_b = second->parent;
	if (first == node_a || !node_b || (!node_b->parent && node_a))
		return (binary_trees_ancestor(first, node_a));
	else if (node_b == second || !node_a || (!node_a->parent && node_b))
		return (binary_trees_ancestor(node_b, second));
	return (binary_trees_ancestor(node_b, node_a));
}
