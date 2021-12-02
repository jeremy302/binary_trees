#include "binary_trees.h"


/**
 * bst_insert - inserts a value into a binary search tree
 * @tree: tree to insert into
 * @value: value to insert
 *
 * Return: the inserted node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *cur, *parent = NULL;

	if (tree == NULL)
		return (NULL);
	node = calloc(1, sizeof(bst_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	if (*tree == NULL)
		return (*tree = node);

	cur = *tree;
	while (cur != NULL)
	{
		parent = cur;
		if (node->n == cur->n)
		{
			free(node);
			return (NULL);
		}
		cur = node->n > cur->n ? parent->right : parent->left;
	}
	if (node->n > parent->n)
		parent->right = node;
	else
		parent->left = node;
	node->parent = parent;
	return (node);
}
