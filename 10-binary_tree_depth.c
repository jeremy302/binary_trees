#include "binary_trees.h"


/**
 * binary_tree_depth - gets the depth of a node
 * @tree: node whose depth to retrieve
 *
 * Return: depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t n = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
		++n, tree = tree->parent;
	return (n);
}
