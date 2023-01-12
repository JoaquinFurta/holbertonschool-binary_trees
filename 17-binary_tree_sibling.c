#include "binary_trees.h"

/**
 * binary_tree_sibling - get the sibling of a node
 * @node: node of which we want the sibling
 *
 * Return: pointer to sibling if it exists, or NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
