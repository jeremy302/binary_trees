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
	binary_tree_t **level, **next_level, *node;
	int i, j, level_len, next_level_len;

	if (tree == NULL || func == NULL)
		return;

	level = calloc(1, sizeof(binary_tree_t *));
	level_len = 1;
	if (level == NULL)
		return;
	level[0] = (binary_tree_t *)tree;
	while (level != NULL && level_len > 0)
	{
		for (next_level_len = 0, i = 0; i < level_len; ++i)
		{
			node = level[i];
			func(node->n);
			next_level_len += (level[i]->left != NULL) +
				(level[i]->right != NULL);
		}
		next_level = calloc(next_level_len, sizeof(binary_tree_t *));
		if (next_level == NULL)
		{
			free(level);
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
		free(level);
		level = next_level;
		level_len = next_level_len;
		if (next_level_len == 0)
			return;
	}
}
