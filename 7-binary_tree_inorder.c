#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses a tree in an "in-order" manner
 * @tree: tree
 * @func: function to be executed
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

