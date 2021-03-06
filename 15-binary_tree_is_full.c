#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if all nodes have 0 or 2 children
 * @tree: tree to check
 *
 * Return: 1 if the tree is full, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
;
}
