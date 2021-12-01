#include "binary_trees.h"


/**
 * tree_height - gets the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (-1);
	lheight = tree_height(tree->left);
	rheight = tree_height(tree->right);
	return (((int)lheight > (int)rheight ? lheight : rheight) + 1);
}

/**
 * binary_tree_balance - measures hegiht difference of a node's children
 * @tree: tree to measure
 *
 * Return: height difference between the left and right node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}
