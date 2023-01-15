#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
bst_t *min_value_in_branch(bst_t *branch);

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
