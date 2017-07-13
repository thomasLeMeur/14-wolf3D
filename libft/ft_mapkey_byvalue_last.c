/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapkey_byvalue_last.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:24 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_mapkey_byvalue_last(t_map *map, t_data *value)
{
	t_data	*tmp;

	if (!value)
		return (NULL);
	tmp = NULL;
	while (map)
	{
		if (!ft_datacmp(map->value, value))
			tmp = map->key;
		map = map->next;
	}
	return (tmp);
}
