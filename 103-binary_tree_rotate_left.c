#include "binary_trees.h"

/**
 * binary_tree_rotate_left - perform a left-rotation on a binary tree
 * @tree: root of the tree
 *
 * Return: pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	tree->parent = tree->right;
	if (tree->parent)
	{
		if (tree->parent->left)
			tree->parent->left->parent = tree;
		tree->right = tree->parent->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
	}
	return (tree->parent);
}
