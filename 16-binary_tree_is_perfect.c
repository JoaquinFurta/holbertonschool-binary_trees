#include "binary_trees.h"
int is_perfectly_balanced(const binary_tree_t *tree);

/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: root node
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);

	return ((left > right) ? left : right);
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: root of tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left && !tree->right)
		return (1 + binary_tree_height(tree->left) -
			binary_tree_height(tree->right));

	if (tree->right && !tree->left)
		return (binary_tree_height(tree->left) -
			(binary_tree_height(tree->right) + 1));

	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: root of tree
 *
 * Return: 1 for full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	return (binary_tree_is_full(tree->right) &
			binary_tree_is_full(tree->left));
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: root of the tree
 *
 * Return: 1 if tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if ((binary_tree_is_full(tree)) &&
			is_perfectly_balanced(tree) == 0)
		return (1);
	return (0);
}

/**
 * is_perfectly_balanced - checks if all subtrees have a balance
 * factor of 0
 * @tree: root of the tree
 *
 * Return: 0 if perfectly balanced, else 1
 */
int is_perfectly_balanced(const binary_tree_t *tree)
{
	int result;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	result = binary_tree_balance(tree) || is_perfectly_balanced(tree->left);
	result += binary_tree_balance(tree) || is_perfectly_balanced(tree->right);

	return (result);
}
