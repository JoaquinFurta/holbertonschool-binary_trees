#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert right-child in
 * @value: value to sotre in the new node
 * Return: a pointer to te new node if succed, NULL if it fails
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;

	if (!parent->right)
	{
		new_node->parent = parent;
		parent->right = new_node;
		new_node->right = NULL;
	}
	else
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
		new_node->parent = parent;

	}

	return (new_node);
}


