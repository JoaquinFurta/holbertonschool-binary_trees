#include "binary_trees.h"
#include <unistd.h>

/**
 * binary_tree_levelorder - go through a binary tree using level-order trav.
 * @tree: root of the tree
 * @func: function to apply to each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (!tree->parent)
		func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
