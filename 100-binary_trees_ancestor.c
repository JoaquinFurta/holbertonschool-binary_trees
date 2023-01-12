#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: pointer to common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *i, *j;

	if (!first || !second)
		return (NULL);

	for (i = first->parent; i; i = i->parent)
	{
		if (i == second)
			return (i);
		for (j = second->parent; j; j = j->parent)
		{
			if (first == j || i == j)
				return (j);
		}
	}
	return (NULL);
}

