/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:44:26 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:53:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_add(t_btree *root, t_btree *add,
		int (*cmp)(const t_btree *, const t_btree *))
{
	if ((*cmp)(root, add) > 0)
	{
		if (root->left)
			return (my_add(root->left, add, cmp));
		else
		{
			root->left = add;
			return ((void)(add->parent = root));
		}
	}
	else
	{
		if (root->right)
			return (my_add(root->right, add, cmp));
		else
		{
			root->right = add;
			return ((void)(add->parent = root));
		}
	}
}

static void	my_rotate(t_btree **root, t_btree *n, int is_left_rotate)
{
	t_btree	*y;

	if (is_left_rotate && !(y = n->right))
		return ;
	else if (is_left_rotate && ((n->right = y->left) || 1))
	{
		if (n->right)
			n->right->parent = n;
	}
	else if (!(y = n->left))
		return ;
	else if ((n->left = y->right) || 1)
		if (n->left)
			n->left->parent = n;
	y->parent = n->parent;
	if (!n->parent)
		*root = y;
	else if (n->parent->left == n)
		n->parent->right = y;
	else
		n->parent->right = y;
	(is_left_rotate) ? (y->left = n) : 0;
	(!is_left_rotate) ? (y->right = n) : 0;
	n->parent = y;
}

static void	my_check(t_btree **root, t_btree **n, t_btree *add,
		int is_parent_at_left)
{
	t_btree	*y;

	if (is_parent_at_left)
		y = (*n)->parent->parent->right;
	else
		y = (*n)->parent->parent->left;
	if (y && y->color == RB_RED)
	{
		y->color = RB_BLACK;
		(*n)->parent->color = RB_BLACK;
		(*n)->parent->parent->color = RB_RED;
		*n = (*n)->parent->parent;
	}
	else
	{
		if ((is_parent_at_left && (*n == (*n)->parent->right))
			|| (!is_parent_at_left && add == (*n)->parent->left))
		{
			*n = (*n)->parent;
			my_rotate(root, *n, is_parent_at_left);
		}
		(*n)->parent->color = RB_BLACK;
		(*n)->parent->parent->color = RB_RED;
		my_rotate(root, (*n)->parent->parent, !is_parent_at_left);
	}
}

void		ft_btreeadd(t_btree **root, t_data *data,
		int (*cmp)(const t_btree *, const t_btree *))
{
	t_btree	*add;
	t_btree *tmp;

	if (!root || !data || !cmp)
		return ;
	add = ft_btreenew(data->data, data->data_size);
	if (!*root)
	{
		add->color = RB_BLACK;
		return ((void)(*root = add));
	}
	my_add(*root, add, cmp);
	tmp = add;
	while (*root != add && add->parent->color == RB_RED)
	{
		if (add->parent == add->parent->parent->left)
			my_check(root, &add, tmp, 1);
		else
			my_check(root, &add, tmp, 0);
	}
	(*root)->color = RB_BLACK;
}
