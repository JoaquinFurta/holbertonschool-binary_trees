#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
heap_t *InsertAtIndex(binary_tree_t *tree, unsigned int index, int value);
heap_t *SiftUp(heap_t *node, heap_t **tree);
int heap_search(heap_t *heap, int value);

/**
 * heap_insert - insert a node in a max heap
 * @root: pointer to root of the heap
 * @value: value to insert
 *
 * Return: pointer to new root
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	int size, is_in_heap;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}

	is_in_heap = heap_search(*root, value);
	if (is_in_heap)
		return (NULL);

	size = binary_tree_size(*root); /* Index of new node should be = size */
	new = InsertAtIndex(*root, size, value);

	new = SiftUp(new, root);
	return (new);
}


/**
 * InsertAtIndex - insert a note at a given index in a binary tree
 * @tree: binary tree in which to insert
 * @index: index at which to insert
 * @value: value which has to be inserted
 *
 * Return: pointer to new node
 */
heap_t *InsertAtIndex(binary_tree_t *tree, unsigned int index, int value)
{
	int height, *array, ar_size, i, j;
	heap_t *new, *parent, *node;

	if (!tree)
		return (NULL);

	height = binary_tree_height(tree);

	if (((index + 1) & (index)) == 0)
/* Note that ((index + 1) & (index)) == 0 if index is a power of 2. If so */
/* the new node will be in a new level (height will increase) */
		ar_size = height + 1;
	else
		ar_size = height;

	array = malloc(sizeof(int) * (ar_size));
	if (!array)
		exit(98);
	for (i = (int) index, j = ar_size - 1; j >= 0 && i >= 0; j--)
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
	for (i = 0, parent = tree, node = parent; i < ar_size; i++)
	{
		if (array[i])
			node = parent->right;
		else
			node = parent->left;
		if (!node)
			break;
		parent = node;
	}
	new = binary_tree_node(parent, value);
	if (array[i])
		parent->right = new;
	else
		parent->left = new;
	free(array);
	return (new);
}

/**
 * SiftUp - sift up in a heap binary tree
 * @node: node which has to be 'sifted up'
 * @tree: pointer to root
 *
 * Return: pointer to new position of sifted node
 */
heap_t *SiftUp(heap_t *node, heap_t **tree)
{
	heap_t *parent;
	int tmp;

	if (!node || !tree)
		return (NULL);

	parent = node->parent;
	if (parent)
	{
		if (parent->n < node->n) /* Switch places */
		{
			tmp = parent->n;
			parent->n = node->n;
			node->n = tmp;
			return (SiftUp(parent, tree));
		}
		else
			return (node);
	}

	*tree = node;
	return (node);
}

/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: root node
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (MAX(1 + binary_tree_height(tree->left),
			1 + binary_tree_height(tree->right)));
}


/**
 * binary_tree_size - get the size of a binary tree
 *
 * @tree: pointer to root of the tree
 *
 * Return: size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_search - search for a node in a max heap tree
 * @heap: root of the heap
 * @value: value we're searching for
 *
 * Return: 1 if found else 0
 */
int heap_search(heap_t *heap, int value)
{
	if (!heap)
		return (0);
	if (heap->n > value)
		return (heap_search(heap->left, value) || heap_search(heap->right, value));
	if (heap->n < value)
		return (0);
	return (1);
}
