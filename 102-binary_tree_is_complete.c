#include "binary_trees.h"
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front, flag, rear;
	binary_tree_t *temp_node;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);
	front = -1, rear = -1, flag = 0;
	temp_node = (binary_tree_t *)tree;
	while (temp_node)
	{
		if (flag)
		{
			if (temp_node->left || temp_node->right)
			{
				free(queue);
				return (0);
			}
		}
		else if (!(temp_node->left && temp_node->right))
			flag = 1;
		if (temp_node->left)
			queue[++rear] = temp_node->left;
		if (temp_node->right)
			queue[++rear] = temp_node->right;
		if (front == rear)
			break;
		temp_node = queue[++front];
	}
	free(queue);
	return (1);
}

