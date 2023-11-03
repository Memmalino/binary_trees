#include "binary_trees.h"
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_leftt(binary_tree_t *tree);
/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: A pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	temp = new_root->left;

	new_root->left = tree;
	tree->right = temp;

	return (new_root);
}

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: A pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	temp = new_root->right;

	new_root->right = tree;
	tree->left = temp;

	return (new_root);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to insert
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if (binary_tree_balance(*tree) > 1 && value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		if (binary_tree_balance(*tree) > 1 && value > (*tree)->left->n)
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if (binary_tree_balance(*tree) < -1 && value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		if (binary_tree_balance(*tree) < -1 && value < (*tree)->right->n)
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (*tree);
}

