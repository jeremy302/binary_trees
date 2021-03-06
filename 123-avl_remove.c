#include "binary_trees.h"

/**
 * smallest - gets the smallest node
 * @node: tree to query
 *
 * Return: node with the smallest value
 */
static bst_t *smallest(bst_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (node);
	return (smallest(node->left));
}

/**
 * remove_node - removes a value from a binary search tree
 * @root: tree to query
 * @value: value of node to remove
 *
 * Return: the parent
 */
static bst_t *remove_node(bst_t **root, int value)
{
	bst_t *node = *root, *parent = NULL, **plink, *new, *src = NULL;

	while (node != NULL)
	{
		if (node->n == value)
		{
			parent = node->parent, src = parent;
			plink = parent == NULL ? root :
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
					*plink = new, new->parent = node->parent, src = node->parent,
						new->left = node->left, new->left->parent = new;
				else
				{
					new->parent->left = new->right, src = new->parent;
					if (new->right)
						new->right->parent = new->parent;
					*plink = new, new->parent = parent, new->left = node->left;
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
	return (src);
}

/**
 * rotate - rotates a binary tree
 * @tree: tree to rotate
 * @direction: direction to rotate in. 1 for right, else left
 *
 * Return: new root
 */
static binary_tree_t *rotate(binary_tree_t *tree, char direction)
{
	binary_tree_t *node, **plink;

	if (tree == NULL)
		return (NULL);
	if (direction == 1)
	{
		if (tree->left == NULL)
			return (tree);
		plink = tree->parent == NULL ? NULL :
			(tree->n  > tree->parent->n ? &tree->parent->right :
			 &tree->parent->left);
		node = tree->left, node->parent = tree->parent;
		tree->left = node->right;
		if (tree->left)
			tree->left->parent = tree;
		tree->parent = node, node->right = tree;
	}
	else
	{
		if (tree->right == NULL)
			return (tree);
		plink = tree->parent == NULL ? NULL :
			(tree->n  > tree->parent->n ? &tree->parent->right :
			 &tree->parent->left);
		node = tree->right, node->parent = tree->parent;
		tree->right = node->left;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent = node, node->left = tree;
	}
	if (plink != NULL)
		*plink = node;
	return (node);
}



/**
 * balance - balances an avl tree
 * @root: root of tree
 * @node: inserted node
 *
 * Return: new root
 */
static avl_t *balance(avl_t *root, avl_t *node)
{
	avl_t *tmp = node, *nroot;
	int balance;

	while (tmp != NULL)
	{
		balance = binary_tree_balance(tmp);
		if (balance < -1 || balance > 1)
		{
			if (balance == 2 && (binary_tree_balance(tmp->left) == 1
				|| binary_tree_balance(tmp->left) == 0))
				nroot = rotate(tmp, 1);
			else if (balance == 2 && binary_tree_balance(tmp->left) == -1)
			{
				tmp->left = rotate(tmp->left, -1);
				nroot =  rotate(tmp, 1);
			}
			else if (balance == -2 && (binary_tree_balance(tmp->right) == -1
				|| binary_tree_balance(tmp->right) == 0))
				nroot = rotate(tmp, -1);
			else if (balance == 2 && binary_tree_balance(tmp->left) == -1)
			{
				tmp->right = rotate(tmp->right, 1);
				nroot = rotate(tmp, -1);
			}
			return (tmp == root ? nroot : root);
		}
		tmp = tmp->parent;
	}
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: tree
 * @value: value to remove
 *
 * Return: new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *src;

	if (root == NULL)
		return (NULL);
	src = remove_node(&root, value);
	root = balance(root, src);
	return (root);
}
