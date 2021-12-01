#include "binary_trees.h"


/**
 * binary_tree_height - gets the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (-1);
	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);
	return (((int)lheight > (int)rheight ? lheight : rheight) + 1);
}
