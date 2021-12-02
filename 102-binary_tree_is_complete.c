#include "binary_trees.h"

/**
 * tree_size - gets the total number of nodes in a tree
 * @tree: tree to count into
 *
 * Return: nodes count
 */
static size_t tree_size(const binary_tree_t *tree)
{
	size_t lsize, rsize;

	if (tree == NULL)
		return (0);

	lsize = tree_size(tree->left);
	rsize = tree_size(tree->right);
	return (lsize + rsize + 1);
}

/**
 * is_complete - checks if a node's position is valid for a complete tree
 * @node: node to check
 * @size: size of tree
 * @ind: index of node
 *
 * Return: 1 if valid, else 0
 */
int is_complete(const binary_tree_t *node, int size, int ind)
{
	if (node == NULL || (node->right != NULL && node->left == NULL))
		return (1);
	if (ind >= size)
		return (0);
	return (is_complete(node->left, size, 2 * ind + 1) &&
			is_complete(node->right, size, 2 * ind + 2));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: tree to check
 *
 * Return: 1 if the tree is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = tree_size(tree);

	return (tree == NULL ? 1 : is_complete(tree, size, 0));
}

