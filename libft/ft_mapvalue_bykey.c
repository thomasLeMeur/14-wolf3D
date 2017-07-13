/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalue_bykey.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:38 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:13 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_mapvalue_bykey(t_map *map, t_data *key)
{
	if (!key)
		return (NULL);
	while (map)
	{
		if (!ft_datacmp(map->key, key))
			return (map->value);
		map = map->next;
	}
	return (NULL);
}
