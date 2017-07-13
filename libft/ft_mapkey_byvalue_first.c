/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapkey_byvalue_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:23 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_mapkey_byvalue_first(t_map *map, t_data *value)
{
	if (!value)
		return (NULL);
	while (map)
	{
		if (!ft_datacmp(map->value, value))
			return (map->key);
		map = map->next;
	}
	return (NULL);
}
