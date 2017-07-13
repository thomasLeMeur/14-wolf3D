/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapitem_byvalue_last.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:19 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:03 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_mapitem_byvalue_last(t_map *map, t_data *value)
{
	t_map	*tmp;

	if (!value)
		return (NULL);
	tmp = NULL;
	while (map)
	{
		if (!ft_datacmp(map->value, value))
			tmp = map;
		map = map->next;
	}
	return (tmp);
}
