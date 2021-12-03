#include "binary_trees.h"


/**
 * tree_height - gets the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);
	lheight = tree_height(tree->left);
	rheight = tree_height(tree->right);
	return (((int)lheight > (int)rheight ? lheight : rheight) + 1);
}

/**
 * is_avl - helper function for `binary_tree_is_avl`
 * @tree: node to check
 *
 * Return: 1 if `nodde` is an AVL tree, esle 0
 */
static int is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (1);
	balance = tree_height(tree->right) - tree_height(tree->left);
	return (is_avl(tree->left) && is_avl(tree->right) &&
			balance >= -1 && balance <= 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * @tree: tree to check
 *
 * Return: 1 if the tree is an AVL tree, else o
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int avl;

	if (tree == NULL)
		return (0);
	avl = is_avl(tree);
	return (avl);
}
