#include "binary_trees.h"
bst_t *insertBST(int value, bst_t *where, bst_t *parent);

/**
 * bst_insert - insert a node in a BST
 * @tree: pointer to root
 * @value: value to insert
 *
 * Return: pointer to newly created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *bst;

	if (!tree || !(*tree))
	{
		bst = (binary_tree_node(NULL, value));
		if (!(*tree))
			*tree = bst;
		return ((bst_t *) bst);
	}
	bst = *tree;
	return (insertBST(value, bst, NULL));
}

/**
 * insertBST - insert a node into a BST
 * @value: value to insert
 * @where: place in which to insert (only insert if where == NULL)
 * @parent: parent of node to be created (where->parent if where != NULL)
 *
 * Return: addess of newly created node
 */
bst_t *insertBST(int value, bst_t *where, bst_t *parent)
{
	bst_t *new;

	if (!where)
	{
		new = ((bst_t *) binary_tree_node((binary_tree_t *) parent,
					value));
		if (parent->n > value)
			parent->left = new;
		else
			parent->right = new;
		return (new);
	}
	else
	{
		if (value > where->n)
			return (insertBST(value, where->right, where));
		if (value < where->n)
			return (insertBST(value, where->left, where));
	}
	return (NULL);
}
