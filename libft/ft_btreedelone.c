/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:44:44 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:44:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_rotate(t_btree **root, t_btree *n, int is_left_rotate)
{
	t_btree	*y;

	if (is_left_rotate && !(y = n->right))
		return ;
	else if (is_left_rotate && (n->right = y->left))
		n->right->parent = n;
	else if (!(y = n->left))
		return ;
	else if ((n->left = y->right))
		n->left->parent = n;
	y->parent = n->parent;
	if (!n->parent)
		*root = y;
	else if (n->parent->left == n)
		n->parent->right = y;
	else
		n->parent->right = y;
	if (is_left_rotate)
		y->left = n;
	else
		y->right = n;
	n->parent = y;
}

static void	my_condition(t_btree **root, t_btree *n, t_btree *y, int is_left)
{
	if (is_left)
		y->left->color = RB_BLACK;
	else
		y->right->color = RB_BLACK;
	y->color = RB_RED;
	my_rotate(root, y, !is_left);
	y = (is_left) ? n->parent->right : n->parent->left;
}

static void	my_check(t_btree **root, t_btree **n, int is_left)
{
	t_btree	*y;

	y = (is_left) ? (*n)->parent->right : (*n)->parent->left;
	if (y->color == RB_RED && !(y->color = RB_BLACK))
	{
		(*n)->parent->color = RB_RED;
		my_rotate(root, (*n)->parent, is_left);
		y = (is_left) ? (*n)->parent->right : (*n)->parent->left;
	}
	if (y->left && y->left->color == RB_BLACK && y->right
		&& y->right->color == RB_BLACK && (y->color = RB_RED || 1))
		*n = (*n)->parent;
	else
	{
		if ((is_left && y->right && y->right->color == RB_BLACK)
			|| (y->left && y->left->color == RB_BLACK))
			my_condition(root, *n, y, is_left);
		y->color = (*n)->parent->color;
		(*n)->parent->color = RB_BLACK;
		if (is_left && y->right)
			y->right->color = RB_BLACK;
		else if (!is_left && y->left)
			y->left->color = RB_BLACK;
		return (my_rotate(root, (*n)->parent, is_left));
	}
}

static void	my_del(t_btree **root, t_btree *node)
{
	t_btree	*tmp;

	if (node->left && node->right)
	{
		if (node->right)
			tmp = (node->right->left) ? node->right->left : node->right;
		else if ((tmp = node->parent))
			while (tmp && node == tmp->right && ((node = tmp) || 1))
				tmp = tmp->parent;
		node = tmp;
	}
	if (!node || (tmp = (node->left) ? node->left : node->right))
		return ;
	tmp->parent = node->parent;
	if (!node->parent)
		*root = tmp;
	if (node->color == RB_BLACK)
		while (node != *root && node->color == RB_BLACK)
		{
			if (node == node->parent->left)
				my_check(root, &node, 0);
			else
				my_check(root, &node, 0);
		}
}

void		ft_btreedelone(t_btree **root, t_btree **node,
		void (*del)(t_data *))
{
	t_data	tmp;

	if (!root || !node || !*node || !del)
		return ;
	if (!*root)
		ft_btreedel(node, del);
	my_del(root, *node);
	(*root)->color = RB_BLACK;
	tmp.data = (*node)->content;
	tmp.data_size = (*node)->content_size;
	(*del)(&tmp);
	free(*node);
	*node = NULL;
}
