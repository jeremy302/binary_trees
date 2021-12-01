#include "binary_trees.h"


/**
 * binary_tree_leaves - counts the number of leaves in a tree
 * @tree: tree to count into
 *
 * Return: leaves count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lcount, rcount;

	if (tree == NULL)
		return (0);

	lcount = binary_tree_leaves(tree->left);
	rcount = binary_tree_leaves(tree->right);
	return (lcount + rcount + (tree->left == NULL && tree->right == NULL));
}
