#include "binary_trees.h"
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))
bst_t *insertBST(int value, bst_t *where, bst_t *parent);

/**
 * avl_insert - insert a node in an AVL tree
 * @tree: address of root node
 * @value: value which we should insert
 *
 * Return: pointer to newly created node on success or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *tmp, *aux = NULL;
	int balance, child_balance;

	new = (avl_t *) bst_insert(tree, value);
	if (!new)
		return (NULL);
	for (tmp = new->parent, child_balance = 0; tmp; tmp = tmp->parent)
	{
		balance = binary_tree_balance(tmp);
		if (balance > 1) /* Have to rotate tree left */
		{
			if (balance * child_balance < 0) /* Have to rotate twice */
				binary_tree_rotate_left(tmp->left);

			aux = binary_tree_rotate_right(tmp);

			if (tmp == *tree) /* Check to see if we have to change root */
				*tree = aux;
			return (new);
		}
		else if (balance < -1) /* Have to rotate tree right */
		{
			if (balance * child_balance < 0) /* Have to rotate twice */
				binary_tree_rotate_right(tmp->right);

			aux = binary_tree_rotate_left(tmp);

			if (tmp == *tree) /* Check to see if we have to change root */
				*tree = aux;
			return (new);
		}
		child_balance = balance;
	}
	return (new);
}

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
