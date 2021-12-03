#include "binary_trees.h"

/**
 * insert - inserts a node to an AVL tree
 * @root: tree's root
 * @array: the sorted array of integers
 * @size: the length of the given array
 *
 * Return: t pointer to the root of thhe AVL tree
 */
avl_t *insert(avl_t *root, int *array, int size)
{
	int *left = NULL, *right = NULL;
	int n1 = 0, n2 = 0, len = 0;
	avl_t *p = NULL, *lc = NULL, *rc = NULL;

	if ((size > 0) && (array != NULL))
	{
		p = malloc(sizeof(avl_t));
		if (p != NULL)
		{
			len = size - 1, n1 = (len / 2),	n2 = len - (len / 2);
			if (n1 > 0)
				left = array, lc = insert(p, left, n1);
			if (n2 > 0)
				right = array + n1 + 1, rc = insert(p, right, n2);
			p->parent = root, p->left = lc, p->right = rc;
			p->n = *(array + (size / 2) - (size % 2 == 0 ? 1 : 0));
		}
	}
	return (p);
}

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: the sorted array
 * @size: size of the array
 *
 * Return: a pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	return (array != NULL ? insert(tree, array, (int)size) : NULL);
}
