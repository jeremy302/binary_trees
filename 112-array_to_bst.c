#include "binary_trees.h"

/**
 * insert - inserts a value into a binary search tree
 * @tree: tree to insert into
 * @value: value to insert
 *
 * Return: the inserted node
 */
static bst_t *insert(bst_t **tree, int value)
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

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: array to build from
 * @size: size of `array`
 *
 * Return: the binary search tree created
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL, *node = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; ++i)
	{
		node = insert(tree, array[i]);
		if (tree == NULL)
			tree = node;
	    /* TODO: free and return NULL on failure*/
	}
	return (tree);
}
