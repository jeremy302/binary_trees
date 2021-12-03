#include "binary_trees.h"

/**
 * insert - inserts a value into a binary search tree
 * @tree: tree to insert into
 * @value: value to insert
 *
 * Return: the inserted node
 */
static bst_t *insert(bst_t **tree, int value)
{
	bst_t *node, *cur, *parent = NULL;

	if (tree == NULL)
		return (NULL);
	node = calloc(1, sizeof(bst_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	if (*tree == NULL)
		return (*tree = node);

	cur = *tree;
	while (cur != NULL)
	{
		parent = cur;
		if (node->n == cur->n)
		{
			free(node);
			return (NULL);
		}
		cur = node->n > cur->n ? parent->right : parent->left;
	}
	if (node->n > parent->n)
		parent->right = node;
	else
		parent->left = node;
	node->parent = parent;
	return (node);
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
 * tree_height - gets the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);
	lheight = tree_height(tree->left);
	rheight = tree_height(tree->right);
	return (((int)lheight > (int)rheight ? lheight : rheight) + 1);
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
	int lheight, rheight, balance;

	while (tmp != NULL)
	{
		lheight = tree_height(tmp->left), rheight = tree_height(tmp->right),
			balance = rheight - lheight;
		if (balance < -1 || balance > 1)
		{
			if (balance == -2 && node->n < tmp->left->n)
				nroot = rotate(tmp, 1);
			else if (balance == -2 && node->n > tmp->left->n)
			{
				tmp->left = rotate(tmp->left, -1);
				nroot =  rotate(tmp, 1);
			}
			else if (balance == 2 && node->n > tmp->right->n)
			{
				nroot =  rotate(tmp, -1);
			}
			else if (balance == 2 && node->n < tmp->right->n)
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
 * array_to_avl - converts an array to an AVL tree
 * @array: array to source
 * @size: size of `array`
 *
 * Return: tree created
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL, *node;
	int value, i;

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < (int)size; ++i)
	{
		value = array[i];
		node = insert(&tree, value);
		if (tree == NULL)
			tree = node;
		/* printf("inserted: %d\n", value); */
		/* binary_tree_print(tree); */
		/* if (node == NULL) */
		/* return (NULL); */
		(void)balance;
		tree = balance(tree, node);
	}
	return (tree == NULL ? NULL : tree);
}
