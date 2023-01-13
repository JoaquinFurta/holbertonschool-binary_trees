#include "binary_trees.h"
size_t max(size_t v1, size_t v2);
void level_order_traversal(const binary_tree_t *node,
		size_t level, void (*func)(int));

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
 * binary_tree_levelorder - traverse a binary tree using level order trav.
 * @tree: root
 * @func: function to apply on each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		level_order_traversal(tree, i, func);
}

/**
 * level_order_traversal - recursive function to traverse in level order
 * a binary tree
 * @node: current node
 * @level: level of node
 * @func: function to apply on node if level is 1
 *
 * Return: void
 */
void level_order_traversal(const binary_tree_t *node,
		size_t level, void (*func)(int))
{
	if (!node || !func)
		return;

	if (level == 0)
		func(node->n);
	else if (level > 0)
	{
		level_order_traversal(node->left, level - 1, func);
		level_order_traversal(node->right, level - 1, func);
	}
}
