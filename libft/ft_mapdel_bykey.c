/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdel_bykey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:06 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapdel_bykey(t_map **map, t_data *key,
		void (*del)(t_data *, t_data *))
{
	t_map	*tmp;

	if (!map || !*map || !key)
		return ;
	tmp = ft_mapitem_bykey(*map, key);
	if (tmp)
	{
		if (tmp == *map)
			*map = tmp->next;
		ft_mapdelone(map, &tmp, del);
	}
}
