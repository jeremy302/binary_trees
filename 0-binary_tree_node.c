#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: node's parent
 * @value: node's value
 *
 * Return: node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;
	return (node);
}
