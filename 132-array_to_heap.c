#include "binary_trees.h"

/**
 * array_to_heap - build a max heap from an array
 * @array: array from which to build the heap
 * @size: array size
 *
 * Return: pointer to heap on success or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
