#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child
 * @parent: parent node
 * @value: node's value
 *
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->right = parent->right;
	if (node->right)
		node->right->parent = node;
	node->left = NULL;
	parent->right = node;
	node->parent = parent;
	return (node);
}

