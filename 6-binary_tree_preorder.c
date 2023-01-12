#include "binary_trees.h"

/**
 * binary_tree_preorder - go through a binary tree using pre-order
 * traversal and apply a function on each node
 * @tree: root node
 * @func: function to apply
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
