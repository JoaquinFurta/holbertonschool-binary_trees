#include "binary_trees.h"
#include <stdlib.h>

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
