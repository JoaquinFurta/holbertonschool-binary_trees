#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performa a right rotation on a binary tree
 * @tree: root of the tree before rotation
 *
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child;
	int which = -1;

	if (!tree)
		return (NULL);

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			which = 0;
		else
			which = 1;
	}
	left_child = tree->left;
	if (left_child)
		left_child->parent = tree->parent;
	tree->parent = tree->left;
	if (left_child)
	{
		if (left_child->right)
			left_child->right->parent = tree;
		tree->left = left_child->right;
		left_child->right = tree;
	}
	(which == 0) ? left_child->parent->left = left_child :
		(which == 1) ? left_child->parent->right = left_child : 0;
	return (left_child);
}

