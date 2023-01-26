#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
heap_t *findNodeAtIndex(heap_t *root, unsigned int index);
void SiftDown(heap_t **root);

/**
 * heap_extract - extract the top element from the heap
 * @root: pointer to root of the heap tree
 *
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int ret_value;
	heap_t *node_to_del;
	size_t size;

	if (!root || !(*root))
		return (0);

	ret_value = (*root)->n;
	size = binary_tree_size((const binary_tree_t *) *root);
	node_to_del = findNodeAtIndex(*root, size - 1);

	(*root)->n = node_to_del->n;
	if (node_to_del->parent)
	{
		if (node_to_del->parent->right == node_to_del)
			node_to_del->parent->right = NULL;
		else
			node_to_del->parent->left = NULL;
	}
	free(node_to_del);

	SiftDown(root);
	return (ret_value);
}

/**
 * SiftDown - perform sift down operation on a max heap
 * @root: pointer to the root
 *
 * Return: void
 */
void SiftDown(heap_t **root)
{
	int tmp;
	heap_t *parent, *max;

	if (!root || !(*root))
		return;

	parent = *root;
	if (!parent->right && !parent->left)
		return;

	if (!parent->left)
		max = parent->right;
	else if (!parent->right)
		max = parent->left;
	else
		max = (parent->left->n > parent->right->n) ? parent->left :
			parent->right;

	if (max->n > parent->n)
	{
		tmp = parent->n;
		parent->n = max->n;
		max->n = tmp;
		SiftDown(&max);
	}
}


/**
 * findNodeAtIndex - find node in a complete binary tree with a given index
 * @root: root of the tree
 * @index: index of the node we're searching for
 *
 * Return: pointer to node, or NULL if not found
 */
heap_t *findNodeAtIndex(heap_t *root, unsigned int index)
{
	int *array, i, j;
	size_t height;
	heap_t *parent, *child;

	if (!root)
		return (NULL);

	height = binary_tree_height((const binary_tree_t *) root);
	if (height == 0)
		return (root);

	array = malloc(sizeof(int) * height);
	if (!array)
		exit(98);

	for (i = index, j = (int) height - 1; i >= 0 && j >= 0; j--)
	{
		if (i % 2 == 0)
		{
			array[j] = 1;
			i = (i - 2) / 2;
		}
		else
		{
			array[j] = 0;
			i = (i - 1) / 2;
		}
	}
	for (i = 0, parent = root, child = parent; parent && i < (int) height; i++)
	{
		if (array[i] == 0)
			child = parent->left;
		else if (array[i] == 1)
			child = parent->right;

		if (!child)
			break;
		parent = child;
	}
	free(array);
	return (parent);
}


/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: a pointer to te new node if succed, NULL if it fails
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
