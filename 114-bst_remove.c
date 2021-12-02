#include "binary_trees.h"

/**
 * smallest - gets the smallest node
 * @node: tree to query
 *
 * Return: node with the smallest value
 */
bst_t *smallest(bst_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (node);
	return (smallest(node->left));
}

/**
 * bst_remove - removes a value from a binary search tree
 * @root: tree to query
 * @value: value of node to remove
 *
 * Return: the new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent, **plink, *right, *new;

	while (node != NULL)
	{
		if (node->n == value)
		{
			parent = node->parent;
			plink = parent == NULL || node == root ? &root :
				parent->n > node->n ? &parent->left : &parent->right;
			if (node->right == NULL && node->left == NULL)
				*plink = NULL;
			else if (node->right == NULL)
				*plink = node->left, node->left->parent = *plink;
			else if (node->left == NULL)
				*plink = node->right, node->right->parent = *plink;
			else
			{
				new = smallest(node->right);
				if (new == node->right)
					*plink = new, new->parent = node->parent;
				else
				{
					right = new->right, *plink = new, new->left = node->left;
					if (node->left)
						node->left->parent = new;
					new->right = node->right;
					if (node->right)
						node->right->parent = new;
					new->parent->left = right;
					if (right != NULL)
						right->parent = new->parent;
					new->parent = node->parent;
				}
			}
			free(node);
			break;
		}
		node = value > node->n ? node->right : node->left;
	}
	return (root);
}
