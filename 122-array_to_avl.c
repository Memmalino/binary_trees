#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_avl - Builds an AVL Tree from an array
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL \\
 *  Tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		root = avl_insert(&root, array[i]);
		if (root == NULL)
			return (NULL);
	}

	return (root);
}

