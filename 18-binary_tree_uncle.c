#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a given node
 * @node: node of which we want to find the uncle
 *
 * Return: pointer to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent, grandparent = parent->parent;
	if (grandparent->left == parent)
		return (grandparent->right);
	return (grandparent->left);
}
