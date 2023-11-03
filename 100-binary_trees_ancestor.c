#include "binary_trees.h"

/**
 * find_lca - Recursive function to find the lowest common ancestor
 * @node: Current node in traversal
 * @first: First node to find ancestor for
 * @second: Second node to find ancestor for
 *
 * Return: Lowest common ancestor or NULL if not found
 */
binary_tree_t *find_lca(const binary_tree_t *node, const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (node == NULL)
		return (NULL);

	if (node == first || node == second)
		return ((binary_tree_t *)node);

	left = find_lca(node->left, first, second);
	right = find_lca(node->right, first, second);

	if (left && right)
		return ((binary_tree_t *)node);

	return (left ? left : right);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	return (find_lca(first, first, second));
}

