#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the common ancestor of 2 nodes
 * @first: a node
 * @second: a node
 *
 * Return: common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *n1 = (binary_tree_t *)first,
		*n2 = (binary_tree_t *)second, *short_node, *long_node;
	int n1_d = 0, n2_d = 0, short_depth, long_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	while (n1->parent != NULL)
		++n1_d, n1 = n1->parent;
	while (n2->parent != NULL)
		++n2_d, n2 = n2->parent;
	if (n1_d > n2_d)
		short_node = (binary_tree_t *)second, short_depth = n2_d,
			long_node = (binary_tree_t *)first, long_depth = n1_d;
	else
		long_node = (binary_tree_t *)second, long_depth = n2_d,
			short_node = (binary_tree_t *)first, short_depth = n1_d;
	while (long_depth != short_depth)
		--long_depth, long_node = long_node->parent;
	while (short_node != NULL && short_node != long_node)
	{
		short_node = short_node->parent;
		long_node = long_node->parent;
	}
	return (short_node);
}
