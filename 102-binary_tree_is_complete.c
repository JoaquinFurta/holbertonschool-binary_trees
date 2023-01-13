#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
void level_order(const binary_tree_t *tree, int level,
		int *index, int *array);
unsigned int _pow(unsigned int a, unsigned int b);

/**
 * _pow - own implementation of pow function
 * @a: number which will be elevated to the power of b
 * @b: power
 *
 * Return: a^b
 */
unsigned int _pow(unsigned int a, unsigned int b)
{
	unsigned int i, res = 1;

	if (b == 0)
		return (1);
	if (a == 0)
		return (0);

	for (i = 0; i < b; i++)
		res *= a;

	return (res);
}

/**
 * binary_tree_height - calculate height of binary tree
 * @tree: root of tree
 *
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (MAX(binary_tree_height(tree->left) + 1,
				binary_tree_height(tree->right) + 1));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: root of tree
 *
 * Return: 1 if true, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i, j, flag;
	unsigned int height, max_nodes;
	int *ar;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	max_nodes = _pow(2, height + 1) - 1;

	ar = malloc(sizeof(int) * max_nodes);
	if (!ar)
		exit(98);
	for (i = 0; (unsigned int) i < max_nodes; i++)
		ar[i] = 2;

	for (i = 0, j = 0; (unsigned int) i <= height; i++)
		level_order(tree, i, &j, ar);

	for (i = 0, flag = 0; (unsigned int) i < max_nodes; i++)
	{
		if (ar[i] == 0)
			flag = 1;
		else if (ar[i] == 1 && flag == 1)
		{
			free(ar);
			return (0);
		}
	}
	free(ar);
	return (1);
}

void level_order(const binary_tree_t *tree, int level,
		int *index, int *array)
{
	int j = *index;

	if (!tree)
	{
		array[j] = (tree) ? 1 : 0;
		++*index;
		return;
	}

	if (level == 0)
	{
		array[j] = (tree) ? 1 : 0;
		++*index;
	}

	else if (level > 0)
	{
		level_order(tree->left, level - 1, index, array);
		level_order(tree->right, level - 1, index, array);
	}
}


