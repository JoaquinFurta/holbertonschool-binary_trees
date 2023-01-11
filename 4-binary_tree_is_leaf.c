#include "binary_trees.h"
/**
 * binary_tree_is_leaf - deletes an entire binary tree
 * @node: pointer to the tree to delete
 * Return: (1) if succed, (0) if it fails
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
