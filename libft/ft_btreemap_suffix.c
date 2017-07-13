/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemap_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:10 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 15:00:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(t_data *data)
{
	if (data->data && data->data_size)
		free(data->data);
}

t_btree		*ft_btreemap_suffix(t_btree *root,
		t_btree *(*f)(const t_data *))
{
	t_data	tmp;
	t_btree	*node;
	t_btree	*left;
	t_btree	*right;

	if (!root || !f)
		return (NULL);
	if (root->left)
		left = ft_btreemap_infix(root->left, f);
	if (root->right)
		right = ft_btreemap_infix(root->right, f);
	tmp.data = root->content;
	tmp.data_size = root->content_size;
	if (!(node = (*f)(&tmp)))
	{
		ft_btreedel(&left, &del);
		ft_btreedel(&right, &del);
		return (NULL);
	}
	if (root->left && (left->parent = node))
		node->left = left;
	if (root->right && (right->parent = node))
		node->right = right;
	return (node);
}
