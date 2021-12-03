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
 * is_heap - checks if a node's position is valid for a complete tree and a heap
 * @node: node to check
 * @size: size of tree
 * @ind: index of node
 *
 * Return: 1 if valid, else 0
 */
int is_heap(const binary_tree_t *node, int size, int ind)
{
	if (node == NULL)
		return (1);
	if (ind >= size || (node->left != NULL && node->n < node->left->n) ||
		(node->right != NULL && node->n < node->right->n))
		return (0);
	return (is_heap(node->left, size, 2 * ind + 1) &&
			is_heap(node->right, size, 2 * ind + 2));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid heap structure
 * @tree: tree to check
 *
 * Return: 1 if the tree is a heap, else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size = tree_size(tree);

	return (tree == NULL ? 0 : is_heap(tree, size, 0));
}


