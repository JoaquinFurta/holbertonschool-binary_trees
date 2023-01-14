#include "binary_trees.h"

/**
 * array_to_bst - build a binary search tree from an array
 * @array: array from which to build a BST
 * @size: array size
 *
 * Return: pointer to root of BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *BST = NULL;

	if (!array)
		return (NULL);

	BST = bst_insert(&BST, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&BST, array[i]);

	return (BST);
}
