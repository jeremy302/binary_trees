#include "binary_trees.h"


/**
 * binary_tree_is_root - checks if a node is the root
 * @node: a node
 *
 * Return: 1 if `node` is a root, else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
