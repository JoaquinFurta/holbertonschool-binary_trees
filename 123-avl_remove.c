#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))
bst_t *min_value_in_branch(bst_t *branch);
bst_t *bst_search_parent_of_node(bst_t *tree, int value);
void rebalance_avl(avl_t **tree);

/**
 * avl_remove - remove a node from an A
 * @root: root of tree
 * @value: value to remove
 *
 * Return: pointer to new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root;

	if (!root)
		return (NULL);

	new_root = (avl_t *) bst_remove(root, value);
	if (!new_root)
		return (new_root);

	rebalance_avl(&new_root);
	return (new_root);
}


/**
 * rebalance_avl - rebalance an AVL tree after a removal
 * @tree: pointer to root node
 *
 * Return: void
 */
void rebalance_avl(avl_t **tree)
{
	int balance;

	if (!tree || !(*tree))
		return;

	rebalance_avl(&(*tree)->left);
	rebalance_avl(&(*tree)->right);

	balance = binary_tree_balance((const binary_tree_t *) *tree);
	if (balance > 1)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left(*tree);
}

/**
 * bst_remove - remove a node from a BST
 * @root: root of tree
 * @value: value to remove
 *
 * Return: pointer to new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (root->n > value) /* Value is in left subtree */
		root->left = bst_remove(root->left, value);
	else if (root->n < value) /* Value is in right subtree */
		root->right = bst_remove(root->right, value);

	else /* root->n == value */
	{
		if (!(root->left) || !(root->right))
		{
			if (root->right)
			{
				root->right->parent = root->parent;
				tmp = root->right;
				free(root), root = NULL;
				return (tmp);
			}
			else
			{
				if (root->left)
					root->left->parent = root->parent;
				tmp = root->left;
				free(root), root = NULL;
				return (tmp);
			}
		} /* If we haven't returned, then two childs */
		tmp = min_value_in_branch(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * min_value_in_branch - find the min value in a bst branch
 * (assuming bst is well sorted)
 * @branch: root of subtree in which we want the min value
 *
 * Return: pointer to min value node
 */
bst_t *min_value_in_branch(bst_t *branch)
{
	if (!branch)
		return (NULL);
	if (!branch->left)
		return (branch);
	return (min_value_in_branch(branch->left));
}
