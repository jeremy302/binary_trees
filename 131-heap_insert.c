#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a heap
 * @root: tree
 * @value: node to insert
 *
 * Return: inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *nxt = *root;

	if (root == NULL)
		return (NULL);
	(void) value, (void) node, (void) nxt, (void)root;
	return (NULL);
}
