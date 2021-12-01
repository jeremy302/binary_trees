#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child
 * @parent: parent node
 * @: node's value
 *
 * Return: new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (printf("returning null\n"), NULL);
	node->n = value;
	node->left = parent->left;
	if (parent->left)
		parent->left->parent = node;
	node->right = NULL;
	parent->left = node;
	node->parent = parent;
	return node;
}
