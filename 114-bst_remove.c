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
	bst_t *node = root, *parent, **plink, *new;

	while (node != NULL)
	{
		if (node->n == value)
		{
			parent = node->parent;
			plink = parent == NULL ? &root :
				parent->n > node->n ? &parent->left : &parent->right;
			if (node->right == NULL && node->left == NULL)
				*plink = NULL;
			else if (node->right == NULL)
				*plink = node->left, node->left->parent = node->parent;
			else if (node->left == NULL)
				*plink = node->right, node->right->parent = node->parent;
			else
			{
				new = smallest(node->right);
				if (new == node->right)
					*plink = new, new->parent = node->parent, new->left = node->left;
				else
				{
					new->parent->left = new->right;
					if (new->right)
						new->right->parent = new->parent;
					new->right = NULL, *plink = new;
					new->parent = parent, new->left = node->left;
					if (new->left)
						new->left->parent = new;
					new->right = node->right;
					if (new->right)
						new->right->parent = new;
				}
			}
			free(node);
			break;
		}
		node = value > node->n ? node->right : node->left;
	}
	return (root);
}
