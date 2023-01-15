#include "binary_trees.h"

/**
 * binary_tree_rotate_left - perform a left-rotation on a binary tree
 * @tree: root of the tree
 *
 * Return: pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child;
	int which = -1;

	if (!tree)
		return (NULL);

	/* Find if tree is right child or left child, or neither*/
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			which = 0;
		else
			which = 1;
	}

	right_child = tree->right;
	if (right_child)
		right_child->parent = tree->parent;
	tree->parent = tree->right;
	if (right_child)
	{
		if (right_child->left)
			right_child->left->parent = tree;
		tree->right = right_child->left;
		right_child->left = tree;
	}
	(which == 0) ? right_child->parent->left = right_child :
		(which == 1) ? right_child->right = right_child : 0;
	return (right_child);
}

