/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreefrom_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:26 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:35 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_cmp(const t_btree *a, const t_btree *b)
{
	if (a->content_size != b->content_size)
		return (a->content_size - b->content_size);
	return (ft_memcmp(a->content, b->content, a->content_size));
}

t_btree		*ft_btreefrom_map(t_map *map)
{
	t_data	add;
	t_btree	*root;

	root = NULL;
	while (map)
	{
		add.data = ((t_list*)map->value)->content;
		add.data_size = ((t_list*)map->value)->content_size;
		ft_btreeadd(&root, &add, &my_cmp);
		map = map->next;
	}
	return (root);
}
