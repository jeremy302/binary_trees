#include "binary_trees.h"

/**
 * heap_to_sorted_array - Creates a sorted array from a max binary heap tree.
 * @heap: A pointer to the max binary heap.
 * @size: A pointer to the resulting array's size value.
 *
 * Return: A pointer to the array, otherwise NULL.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	heap_t *root;
	int val;
	size_t n = 0;

	if (heap != NULL)
		for (root = heap; root != NULL; n++)
		{
			val = heap_extract(&root);
			array = realloc(array, sizeof(int) * (n + 1));
			*(array + n) = val;
		}
	if (size != NULL)
		*size = n;
	return (array);
}
