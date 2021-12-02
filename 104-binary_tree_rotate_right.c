#include "binary_trees.h"


/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: tree to rotate
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (tree);
	node = tree->left;
	node->parent = NULL;

	tree->left = node->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent = node;
	node->right = tree;
	return (node);
}
