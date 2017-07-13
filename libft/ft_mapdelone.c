/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:14 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_del(t_map **map, void (*del)(t_data *, t_data *))
{
	(*del)((*map)->key, (*map)->value);
	free(*map);
	*map = NULL;
}

void		ft_mapdelone(t_map **map, t_map **rem,
		void (*del)(t_data *, t_data *))
{
	t_map	*tmp;

	if (!map || !rem || !*rem)
		return ;
	if (!*map)
		return (my_del(rem, del));
	tmp = *map;
	if (tmp == *rem)
	{
		*map = (*map)->next;
		return (my_del(rem, del));
	}
	while (tmp->next)
	{
		if (tmp->next == *rem)
		{
			tmp->next = (*rem)->next;
			return (my_del(rem, del));
		}
		tmp = tmp->next;
	}
	my_del(rem, del);
}
