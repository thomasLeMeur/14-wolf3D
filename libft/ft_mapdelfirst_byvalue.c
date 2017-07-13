/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelfirst_byvalue.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:11 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapdelfirst_byvalue(t_map **map, t_data *value,
		void (*del)(t_data *, t_data *))
{
	t_map	*tmp;

	if (!map || !value)
		return ;
	tmp = *map;
	while (tmp)
	{
		if (!ft_datacmp(tmp->value, value))
		{
			if (tmp == *map)
				*map = tmp->next;
			ft_mapdelone(map, &tmp, del);
			return ;
		}
		tmp = tmp->next;
	}
}
