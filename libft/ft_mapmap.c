/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:27 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:07 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_del(t_data *a, t_data *b)
{
	if (a->data && a->data_size && b->data && b->data_size)
	{
		free(a->data);
		free(b->data);
	}
}

t_map		*ft_mapmap(t_map *map, t_map *(*f)(const t_map *other))
{
	t_map	*add;
	t_map	*tmp;

	if (!map || !f || !(add = (*f)(map)))
		return (NULL);
	map = map->next;
	tmp = add;
	while (map)
	{
		if (!(tmp->next = (*f)(map)))
		{
			ft_mapdel(&add, &my_del);
			return (NULL);
		}
		tmp = tmp->next;
		map = map->next;
	}
	return (add);
}
