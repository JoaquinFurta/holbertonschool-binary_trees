#include "binary_trees.h"
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
 * heap_to_sorted_array - implement heapsort from a max heap
 * @heap: pointer to root of the heap
 * @size: pointer to variable in which we'll store the array size
 *
 * Return: sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i;
	int *array;

	if (!heap)
		return (NULL);

	*size = binary_tree_size((const binary_tree_t *) heap);
	array = malloc(sizeof(int) * (*size));
	if (!array)
		exit(98);

	for (i = 0; i < *size; i++)
		array[i] = heap_extract(&heap);

	return (array);
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
