#include "binary_trees.h"
size_t max(size_t v1, size_t v2);

/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: root node
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (max(1 + binary_tree_height(tree->left),
			1 + binary_tree_height(tree->right)));

}

/**
 * max - calculate the max of two values
 * @v1: value 1
 * @v2: value 2
 *
 * Return: max(v1, v2)
 */
size_t max(size_t v1, size_t v2)
{
	return ((v1 > v2) ? v1 : v2);
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
