#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using\\
 * level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front, rear;
	binary_tree_t *temp_node;
	binary_tree_t **queue;

	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	front = -1, rear = -1;
	temp_node = (binary_tree_t *)tree;

	while (temp_node)
	{
		func(temp_node->n);

		if (temp_node->left)
			queue[++rear] = temp_node->left;
		if (temp_node->right)
			queue[++rear] = temp_node->right;

		if (front == rear)
			break;

		temp_node = queue[++front];
	}

	free(queue);
}

