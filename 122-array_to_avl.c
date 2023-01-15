#include "binary_trees.h"

/**
 * array_to_avl - build an AVL out of an array
 * @array: array of ints
 * @size: size of array
 *
 * Return: pointer to AVL on success, NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array || size < 1)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
