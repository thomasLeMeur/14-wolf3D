/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemap_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:46 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 15:00:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(t_data *data)
{
	if (data->data && data->data_size)
		free(data->data);
}

t_btree		*ft_btreemap_infix(t_btree *root,
		t_btree *(*f)(const t_data *))
{
	t_data	tmp;
	t_btree	*node;
	t_btree	*left;

	if (!root || !f)
		return (NULL);
	if (root->left)
		left = ft_btreemap_infix(root->left, f);
	tmp.data = root->content;
	tmp.data_size = root->content_size;
	if (!(node = (*f)(&tmp)))
	{
		ft_btreedel(&left, &del);
		return (NULL);
	}
	if (root->left && (left->parent = node))
		node->left = left;
	if (root->right)
	{
		node->right = ft_btreemap_infix(root->right, f);
		node->right->parent = node;
	}
	return (node);
}
