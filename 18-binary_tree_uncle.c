#include "binary_trees.h"

/**
 * binary_tree_uncle - gets the sibling of the parent of a node
 * @node: a node
 *
 * Return: uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	node = node->parent;
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (node->parent->left == node ?
			node->parent->right :
			node->parent->left);
}
