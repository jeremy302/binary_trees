#include "binary_trees.h"

/**
 * binary_tree_size - gets the total number of nodes in a tree
 * @tree: tree to count into
 *
 * Return: nodes count
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lsize, rsize;

	if (tree == NULL)
		return (0);

	lsize = binary_tree_size(tree->left);
	rsize = binary_tree_size(tree->right);
	return (lsize + rsize + 1);
}
