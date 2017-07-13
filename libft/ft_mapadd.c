/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:03 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapadd(t_map **map, t_map *other)
{
	t_map	*tmp;

	if (!map || !other)
		return ;
	if (!*map)
		return ((void)(*map = other));
	if (other->next)
		return (ft_mapmerge(map, other));
	if (ft_datacmp((*map)->key, other->key) > 0)
	{
		other->next = *map;
		return ((void)(*map = other));
	}
	tmp = *map;
	while (tmp->next)
	{
		if (ft_datacmp(tmp->next->key, other->key) > 0)
		{
			other->next = tmp->next;
			return ((void)(tmp->next = other));
		}
		tmp = tmp->next;
	}
	tmp->next = other;
}
