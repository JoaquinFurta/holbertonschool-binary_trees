#include "binary_trees.h"
size_t max(size_t v1, size_t v2);

/**
 * binary_tree_depth - calculate the depth of a binary tree
 * @tree: root node
 *
 * Return: height
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * max - calculate the max of two values
 * @v1: value 1
 * @v2: value 2
 *
 * Return: max(v1, v2)
 */
size_t max(size_t v1, size_t v2)
{
	return ((v1 > v2) ? v1 : v2);
}


