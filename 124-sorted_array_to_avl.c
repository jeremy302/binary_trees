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
 * sorted_array_to_avl - converts a sorted array to an AVL tree
 * @array: array to source
 * @size: size of `array`
 *
 * Return: created tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int mid;

	if (array == NULL || size == 0)
		return (NULL);

	mid = (size - 1) / 2;
	printf("inserting: %d (index %d)\n", array[mid], mid);
	insert(&root, array[mid]);
	root->left = sorted_array_to_avl(array, mid);
	if (root->left != NULL)
		root->left->parent = root;
	root->right = sorted_array_to_avl(array + mid + 1, (size - mid) - 1);
	if (root->right != NULL)
		root->right->parent = root;
	return (root);
}
