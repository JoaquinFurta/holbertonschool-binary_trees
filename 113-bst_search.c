#include "binary_trees.h"

/**
 * bst_search - search for a value in a binary search tree
 * @tree: BST
 * @value: value to search
 *
 * Return: pointer to node if it is in the BST, else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *ret;

	if (!tree)
		return (NULL);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->n < value)
		return (bst_search(tree->right, value));

	ret = tree->parent;
	return ((ret->right && ret->right->n == value) ? ret->right :
		       ret->left);
}
