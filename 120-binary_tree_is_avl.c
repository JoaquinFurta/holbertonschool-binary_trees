#include "binary_trees.h"
#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : (-x))

int isAVL(const binary_tree_t *tree);
int recursive_comparison(const binary_tree_t *root,
		binary_tree_t *branch, int direction);

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * @tree: root of binary tree
 *
 * Return: 1 if true, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isAVL(tree));
}


/**
 * isAVL - checks if a binary tree is an AVL
 * @tree: root of tree
 *
 * Return: 1 for true, else 0
 */
int isAVL(const binary_tree_t *tree)
{
	int balance, bst;
	int GREATER = 1, LESSER = 0;

	if (!tree)
		return (1);

	balance = binary_tree_balance(tree);
	if ((ABS(balance)) > 1)
		return (0);

	bst = recursive_comparison(tree, tree->right, LESSER) &&
		recursive_comparison(tree, tree->left, GREATER);
	if (!bst)
		return (0);

	return (isAVL(tree->left) && isAVL(tree->right));
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
 * binary_tree_height - calculate the height of a binary tree
 * @tree: root of the tree
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (MAX(1 + binary_tree_height(tree->left),
				1 + binary_tree_height(tree->right)));
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
