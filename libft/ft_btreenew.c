/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:23 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(const void *content, size_t content_size)
{
	t_btree	*tmp;

	if ((tmp = (t_btree*)malloc(sizeof(t_btree))))
	{
		if (!(tmp->content = ft_memdup(content, content_size)))
		{
			free(tmp);
			return (NULL);
		}
		tmp->content_size = content_size;
		tmp->color = RB_RED;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->parent = NULL;
	}
	return (tmp);
}
