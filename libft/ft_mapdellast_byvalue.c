/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdellast_byvalue.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:12 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapdellast_byvalue(t_map **map, t_data *value,
		void (*del)(t_data *, t_data *))
{
	t_map	*tmp;
	t_map	*rem;

	if (!map || !*map || !value)
		return ;
	tmp = *map;
	rem = NULL;
	while (tmp)
	{
		if (!ft_datacmp(tmp->value, value))
			rem = tmp;
		tmp = tmp->next;
	}
	if (rem)
	{
		if (rem == *map)
			*map = rem->next;
		ft_mapdelone(map, &rem, del);
	}
}
