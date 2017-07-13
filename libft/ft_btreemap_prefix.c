/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemap_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:48 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 15:00:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(t_data *data)
{
	if (data->data && data->data_size)
		free(data->data);
}

t_btree		*ft_btreemap_prefix(t_btree *root,
		t_btree *(*f)(const t_data *))
{
	t_data	tmp;
	t_btree	*node;

	if (!root || !f)
		return (NULL);
	tmp.data = root->content;
	tmp.data_size = root->content_size;
	if (!(node = (*f)(&tmp)))
		return (NULL);
	if (root->left)
	{
		if (!(node->left = ft_btreemap_prefix(root->left, f)))
			return (NULL);
		node->left->parent = node;
	}
	if (root->right)
	{
		if (!(node->right = ft_btreemap_prefix(root->right, f)))
		{
			ft_btreedel(&root, &del);
			return (NULL);
		}
		node->right->parent = node;
	}
	return (node);
}
