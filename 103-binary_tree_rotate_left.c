#include "binary_trees.h"


/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: tree to rotate
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (tree);
	node = tree->right;
	node->parent = NULL;

	tree->right = node->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent = node;
	node->left = tree;
	return (node);
}
