#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performa a right rotation on a binary tree
 * @tree: root of the tree before rotation
 *
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	tree->parent = tree->left;
	if (tree->parent)
	{
		if (tree->parent->right)
			tree->parent->right->parent = tree;
		tree->left = tree->parent->right;
		tree->parent->right = tree;
		tree->parent->parent = NULL;
	}
	return (tree->parent);
}
