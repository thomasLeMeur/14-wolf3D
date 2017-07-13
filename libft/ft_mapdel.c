/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:05 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapdel(t_map **map, void (*del)(t_data *, t_data *))
{
	t_map	*tmp;

	if (!map)
		return ;
	tmp = *map;
	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		ft_mapdelone(map, &tmp, del);
	}
}
