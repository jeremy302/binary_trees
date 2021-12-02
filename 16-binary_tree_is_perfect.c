#include "binary_trees.h"


/**
 * tree_is_perfect - helper for the `binary_tree_is_perfect` function
 * @tree: tree to check
 *
 * Return: 0 if tree isn't perfect, else the size
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int lp, rp;

	if (tree == NULL)
		return (1);
	if ((tree->left == NULL) != (tree->right == NULL))
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	lp = tree_is_perfect(tree->left);
	rp = tree_is_perfect(tree->right);
	return (lp == 0 || rp == 0 ? 0 : lp + rp + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check
 *
 * Return: 1 if the tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lc, rc;

	if (tree == NULL)
		return (0);
	lc = tree_is_perfect(tree->left);
	rc = tree_is_perfect(tree->right);
	return (tree != NULL && lc != 0 && lc == rc);
}
