#include "binary_trees.h"

/**
 * enqueue_item - enqueue an item
 * @head: a pointer to the queue's head
 * @tail: a pointer to the queue's tail
 * @n: a pointer to the queue's size
 * @item: the item to enqueue
 */
static void enqueue_item(heap_t **head, heap_t **tail,	int *n, void *item)
{
	heap_t *new_node;
	heap_t *node = (heap_t *)item;

	if ((head != NULL) && (tail != NULL))
	{
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return;
		new_node->left = *tail;
		new_node->right = NULL;
		new_node->n = (node != NULL ? node->n : -1);
		new_node->parent = node;
		if (*head == NULL)
			*head = new_node;
		if (*tail != NULL)
			(*tail)->right = new_node;
		*tail = new_node;
		if (n != NULL)
			(*n)++;
	}
}

/**
 * dequeue_item - removes an item from a queue
 * @queue_h: the queue's head
 * @queue_t: the queue's tail
 * @n: a pointer to the queue's size
 *
 * Return: the value of the removed queue
 */
static heap_t *dequeue_item(heap_t **queue_h,
	heap_t **queue_t, int *n)
{
	heap_t *tmp0;
	heap_t *tmp1;
	heap_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		tmp0 = *queue_h;
		if (tmp0 != NULL)
		{
			node = tmp0->parent;
			if (tmp0->right != NULL)
			{
				tmp1 = tmp0->right;
				tmp1->left = NULL;
				*queue_h = tmp1;
				free(tmp0);
			}
			else
			{
				free(tmp0);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * get_insert_position - gets an insert position
 * @root: the root of the max binary heap tree
 *
 * Return: the insert position
 */
static heap_t *get_insert_position(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *parent_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				if (current->parent->left != NULL)
				{
					enqueue_item(&head, &tail, &n, (void *)(current->parent->left));
					if (current->parent->right != NULL)
					{
						enqueue_item(&head, &tail, &n, (void *)(current->parent->right));
					}
					else
					{
						parent_node = current->parent;
						break;
					}
				}
				else
				{
					parent_node = current->parent;
					break;
				}
			}
			dequeue_item(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item(&head, &tail, &n);
	}
	return (parent_node);
}

/**
 * lift_up - swap node with parent
 * @node: the node's address
 * @tree: the root of the tree
 */
static void lift_up(heap_t **node, heap_t **tree)
{
	heap_t *tmp, *p, *gpnode, *l, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (tree != NULL))
	{
		p = (*node)->parent, tmp = *node, gpnode = (*node)->parent->parent;
		l = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node)
		{
			if ((gpnode != NULL) && (gpnode->left == (*node)->parent))
				gpnode->left = *node;
			if ((gpnode != NULL) && (gpnode->right == (*node)->parent))
				gpnode->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = tmp;
			(*node)->parent = gpnode, (*node)->left = p->left, (*node)->right = p;
			p->parent = tmp, p->left = l, p->right = r;
		}
		else
		{
			if ((gpnode != NULL) && (gpnode->left == p))
				gpnode->left = *node;
			if ((gpnode != NULL) && (gpnode->right == p))
				gpnode->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = gpnode, (*node)->right = p->right, (*node)->left = p,
			p->parent = tmp, p->left = l, p->right = r;
		}
		if (l != NULL)
			l->parent = p;
		if (r != NULL)
			r->parent = p;
		if (gpnode == NULL)
			*tree = tmp;
	}
}

/**
 * heap_insert - inserts a value into a max heap tree
 * @root: a pointer to the root of the tree
 * @value: the value to insert.
 *
 * Return: a pointer to the inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL, *parent = NULL;

	if (root != NULL)
	{
		parent = get_insert_position(*root);
		node = malloc(sizeof(heap_t));
		if (node == NULL)
			return (node);
		node->left = NULL;
		node->right = NULL;
		node->parent = parent;
		node->n = value;
		if (parent == NULL)
			*root = node;
		else
		{
			if (parent->left == NULL)
				parent->left = node;
			else
				parent->right = node;
			while (node->parent != NULL)
			{
				if (node->n > node->parent->n)
					lift_up(&node, root);
				else
					break;
			}
		}
	}
	return (node);
}
