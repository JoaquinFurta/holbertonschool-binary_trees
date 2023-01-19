#include "binary_trees.h"
avl_t *addNodeFromArray(avl_t *parent, int *ar, int size);

/**
 * sorted_array_to_avl - create an AVL from a sorted array of ints
 * @array: pointer to first element
 * @size: size of the array
 *
 * Return: pointer to the AVL or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = addNodeFromArray(root, array, size);
	return (root);
}


/**
 * addNodeFromArray - add a node to an AVL tree from a sorted array recursively
 * @parent: parent of node to add from
 * @ar: array
 * @size: size of array
 *
 * Return: pointer to added node
 */
avl_t *addNodeFromArray(avl_t *parent, int *ar, int size)
{
	int even = !(size % 2);
	avl_t *new;

	if (size < 1)
		return (NULL);

	new = binary_tree_node(parent, ar[size / 2 - even]);
	if (parent)
	{
		if (parent->n > new->n)
			parent->left = new;
		else
			parent->right = new;
	}

	addNodeFromArray(new, ar, size / 2 - even);
	addNodeFromArray(new, &ar[size / 2 - even + 1], size - (size / 2) - 1 + even);

	return (new);
}
