#include "binary_trees.h"


/**
 * is_bst - helper for the `binary_tree_is_bst` method
 * @node: node to check
 * @lo: min value
 * @hi: max value
 *
 * Return: 1 if node is a binary search tree, else 0
 */
int is_bst(const binary_tree_t *node, int lo, int hi)
{
	if (node == NULL)
		return (1);
	return (node->n > lo && node->n < hi &&
			is_bst(node->left, lo, node->n) &&
			is_bst(node->right, node->n, hi));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a binary search tree
 * @tree: tree to check
 *
 * Return: 1 if it is a tree, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, -1000000, 1000000));
}
