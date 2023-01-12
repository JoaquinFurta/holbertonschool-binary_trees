#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert left-child in
 * @value: value to sotre in the new node
 * Return: a pointer to te new node if succed, NULL if it fails
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->right = NULL;

	if (!parent->left)
	{
		new_node->parent = parent;
		parent->left = new_node;
		new_node->left = NULL;
	}
	else
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
		parent->left = new_node;
		new_node->parent = parent;

	}

	return (new_node);
}


