#include "binary_trees.h"


/**
 * binary_tree_levelorder - traverses a tree in a "level-order" manner
 * @tree: tree to traverse
 * @func: function to be executed
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **level, **next_level, *node;
	int i, j, level_len, next_level_len;

	if (tree == NULL || func == NULL)
		return;
	level = calloc(1, sizeof(binary_tree_t *)), level_len = 1;
	if (level == NULL)
	{
		func(tree->n);
		return;
	}
	level[0] = tree;
	while (1)
	{
		for (next_level_len = 0, i = 0; i < level_len; ++i)
		{
			node = level[i], func(node->n);
			next_level_len += (node->left != NULL) + (node->right != NULL);
		}
		next_level = next_level_len ?
			calloc(next_level_len, sizeof(binary_tree_t *)) : NULL;
		if (next_level == NULL)
		{
			free(level), free(next_level);
			return;
		}
		for (j = 0, i = 0; i < level_len; ++i)
		{
			node = level[i];
			if (node->left != NULL)
				next_level[j++] = node->left;
			if (node->right != NULL)
				next_level[j++] = node->right;
		}
		free(level), level = next_level, level_len = next_level_len;
	}
}
