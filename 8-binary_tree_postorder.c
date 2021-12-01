#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a tree in post "post-order" manner
 * @tree: tree
 * @func: function to be executed
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

