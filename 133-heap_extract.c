#include "binary_trees.h"

/**
 * enqueue_item - enqueues an item
 * @head: a pointer to the head
 * @tail: a pointer to the tail
 * @n: a pointer to the queue's size
 * @item: the item to add
 */
void enqueue_item(heap_t **head, heap_t **tail, int *n, void *item)
{
	heap_t *new_node;

	if ((head != NULL) && (tail != NULL))
	{
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return;
		new_node->left = *tail;
		new_node->right = NULL;
		new_node->n = (item != NULL ? ((heap_t *)item)->n : -1);
		new_node->parent = (heap_t *)item;
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
 * @head: a pointer to the head
 * @tail: a pointer to the tail
 * @n: a pointer to the queue's size
 *
 * Return: the value of the removed item
 */
heap_t *dequeue_item(heap_t **head, heap_t **tail, int *n)
{
	heap_t *tmp0;
	heap_t *tmp1;
	heap_t *node = NULL;

	if ((head != NULL) && (tail != NULL))
	{
		tmp0 = *head;
		if (tmp0 != NULL)
		{
			node = tmp0->parent;
			if (tmp0->right != NULL)
			{
				tmp1 = tmp0->right;
				tmp1->left = NULL;
				*head = tmp1;
				free(tmp0);
			}
			else
			{
				free(tmp0);
				*head = NULL;
				*tail = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * get_last - gets the last level order node
 * @root: the root of the max binary heap tree
 *
 * Return: a pointer to the node
 */
heap_t *get_last(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *last_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				last_node = current->parent;
				if (current->parent->left != NULL)
				{
					enqueue_item(&head, &tail, &n, (void *)(current->parent->left));
				}
				if (current->parent->right != NULL)
				{
					enqueue_item(&head, &tail, &n, (void *)(current->parent->right));
				}
			}
			dequeue_item(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item(&head, &tail, &n);
	}
	return (last_node);
}

/**
 * lift_up - lifts up a node
 * @node: a pointer to the node's address
 * @root: a pointer to the root
 */
void lift_up(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *p, *tmp, *l, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		p = (*node)->parent, node_copy = *node, tmp = (*node)->parent->parent;
		l = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node)
		{
			if ((tmp != NULL) && (tmp->left == (*node)->parent))
				tmp->left = *node;
			if ((tmp != NULL) && (tmp->right == (*node)->parent))
				tmp->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_copy;
			(*node)->parent = tmp, (*node)->left = p->left, (*node)->right = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		else
		{
			if ((tmp != NULL) && (tmp->left == p))
				tmp->left = *node;
			if ((tmp != NULL) && (tmp->right == p))
				tmp->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = tmp, (*node)->right = p->right, (*node)->left = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		if (l != NULL)
			l->parent = p;
		if (r != NULL)
			r->parent = p;
		if (tmp == NULL)
			*root = node_copy;
	}
}

/**
 * heap_extract - extracts the root node of a max binary heap tree
 * @root: a pointer to the address of the tree's root node
 *
 * Return: the value of the extracted node
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *node_l, *node_r, *tmp, *dummy;
	int value = 0, val_l, val_r;

	if ((root != NULL) && (*root != NULL))
	{
		node = *root;
		node_l = node->left;
		node_r = node->right;
		value = node->n;
		tmp = get_last(node);
		*root = ((tmp != NULL) && (tmp->parent != NULL) ? tmp : NULL);
		if ((tmp != NULL) && (tmp->parent != NULL))
		{
			if (tmp->parent->left == tmp)
				tmp->parent->left = NULL;
			if (tmp->parent->right == tmp)
				tmp->parent->right = NULL;
			tmp->parent = NULL;
			tmp->left = (node_l != tmp ? node_l : NULL);
			tmp->right = (node_r != tmp ? node_r : NULL);
			if ((node_l != NULL) && (node_l != tmp))
				node_l->parent = tmp;
			if ((node_r != NULL) && (node_r != tmp))
				node_r->parent = tmp;
			while (tmp != NULL)
			{
				val_l = tmp->left != NULL ? tmp->left->n : tmp->n;
				val_r = tmp->right != NULL ? tmp->right->n : tmp->n;
				dummy = val_l > val_r ? tmp->left : tmp->right;
				if ((dummy != NULL) && (dummy->n > dummy->parent->n))
					lift_up(&dummy, root);
				else
					break;
			}
		}
		free(node);
	}
	return (value);
}
