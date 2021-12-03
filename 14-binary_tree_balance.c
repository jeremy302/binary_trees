#include "binary_trees.h"


/**
 * btree_height - gets the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree
 */
size_t btree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (0);
	lheight = btree_height(tree->left);
	rheight = btree_height(tree->right);
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
	return (btree_height(tree->left) - btree_height(tree->right));
}
