/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapitem_byvalue_first.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:16 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_mapitem_byvalue_first(t_map *map, t_data *value)
{
	if (!value)
		return (NULL);
	while (map)
	{
		if (!ft_datacmp(map->value, value))
			return (map);
		map = map->next;
	}
	return (NULL);
}
