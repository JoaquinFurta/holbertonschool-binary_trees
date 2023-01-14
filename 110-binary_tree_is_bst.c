#include "binary_trees.h"
int recursive_comparison(const binary_tree_t *root,
		binary_tree_t *branch, int direction);

/**
 * binary_tree_is_bst - check if a binary tree is a binary search tree
 * @tree: root of the tree
 *
 * Return: 1 if it is a BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int balanced_root;
	int GREATER = 1, LOWER = 0;

	if (!tree)
		return (0);

	balanced_root = recursive_comparison(tree, tree->left, GREATER) &&
		recursive_comparison(tree, tree->right, LOWER);

	if (balanced_root)
	{
		if (tree->left)
			if (tree->n < tree->left->n)
				return (0);
		if (tree->right)
			if (tree->n > tree->right->n)
				return (0);
		if (!tree->left || tree->right)
			return (1);

		return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
	}
	return (0);
}

/**
 * recursive_comparison - recursively compares the root of a tree or subtree
 * with the value of all the nodes below it
 * @root: root of tree
 * @branch: branch of the root
 * @direction: direction of the comparison (1 for greater, 0 for lower)
 *
 * Return: 1 if root is greater/lower or equal than all nodes below it
 */
int recursive_comparison(const binary_tree_t *root,
		binary_tree_t *branch, int direction)
{
	if (!root)
		return (0);
	if (!branch)
		return (1);

	if (direction == (root->n > branch->n) && root->n != branch->n)
	{
		return (recursive_comparison(root, branch->right, direction) &&
				recursive_comparison(root, branch->left, direction));
	}
	return (0);
}
