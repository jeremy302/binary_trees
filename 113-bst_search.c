#include "binary_trees.h"


/**
 * bst_search - searches a binary search tree for a value
 * @tree: tree to search
 * @value: value to search for
 *
 * Return: match node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *node;

	node = tree;
	while (node != NULL)
	{
		if (node->n == value)
			return ((bst_t *)node);
		node = value > node->n ? node->right : node->left;
	}
	return (NULL);
}
