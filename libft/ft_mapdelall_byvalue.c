/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelall_byvalue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:10 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:58 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapdelall_byvalue(t_map **map, t_data *value,
		void (*del)(t_data *, t_data *))
{
	t_map	*tmp;
	t_map	*rem;

	if (!map || !value)
		return ;
	while (*map && !ft_datacmp((*map)->value, value))
	{
		tmp = *map;
		*map = tmp->next;
		ft_mapdelone(map, &tmp, del);
	}
	tmp = *map;
	while (tmp)
	{
		if (!ft_datacmp(tmp->value, value))
		{
			rem = tmp;
			tmp = tmp->next;
			ft_mapdelone(map, &rem, del);
		}
		else
			tmp = tmp->next;
	}
}
