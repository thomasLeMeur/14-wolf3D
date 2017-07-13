/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapitem_bykey.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:15 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_mapitem_bykey(t_map *map, t_data *key)
{
	if (!key)
		return (NULL);
	while (map)
	{
		if (ft_dataequ(map->key, key))
			return (map);
		map = map->next;
	}
	return (map);
}
