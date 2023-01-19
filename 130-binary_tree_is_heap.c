#include "binary_trees.h"
int isComplete(const binary_tree_t *tree, unsigned int index,
		unsigned int size);
int isHeap(const binary_tree_t *tree, int max_or_min);

/**
 * binary_tree_is_heap - check if a binary tree is a Max heap
 * @tree: root of the tree
 * Return: 1 if true, else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int complete, max_heap_condition;
	unsigned int size;
	const int MAX = 1;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	complete = isComplete(tree, 0, size);

	if (!complete)
		return (0);

	max_heap_condition = isHeap(tree, MAX);
	if (!max_heap_condition)
		return (0);

	return (1);
}

/**
 * isComplete - checks if a binary tree is complete
 * @tree: root of the tree
 * @index: index as if it was an array
 * @size: n of elements in tree
 *
 * Return: 1 if complete, else 0
 */
int isComplete(const binary_tree_t *tree, unsigned int index,
		unsigned int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (isComplete(tree->left, 2 * index + 1, size) &&
			isComplete(tree->right, 2 * index + 2, size));
}


/**
 * binary_tree_size - calculate the size of a binary tree
 * @tree: root
 *
 * Return: n of nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * isHeap - checks if a binary tree is a heap (assuming it is complete)
 * @tree: root of the tree
 * @max_or_min: condition for max or min heap. 1 for max, 0 for min
 *
 * Return: 1 if heap, else 0
 */
int isHeap(const binary_tree_t *tree, int max_or_min)
{
	if (!tree)
		return (1);

	if (tree->right)
		if (max_or_min == (tree->n < tree->right->n))
			return (0);
	if (tree->left)
		if (max_or_min == (tree->n < tree->left->n))
			return (0);

	return (isHeap(tree->right, max_or_min) && isHeap(tree->left, max_or_min));
}
