/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsort_bykey.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:35 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:11 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_sort(t_map **i, t_map **j, t_map *prev,
		int (*cmp)(const t_data *, const t_data *))
{
	t_map	*swap1;
	t_map	*swap2;

	if ((*cmp)((*i)->key, (*j)->next->key) > 0)
	{
		if (*j == *i)
		{
			*i = (*j)->next;
			(*j)->next = (*j)->next->next;
			(*i)->next = *j;
			return ((void)((prev) ? (prev->next = *i) : 0));
		}
		else
		{
			swap1 = *i;
			swap2 = (*j)->next->next;
			*i = (*j)->next;
			(*j)->next = swap1;
			(*i)->next = swap1->next;
			swap1->next = swap2;
			if (prev)
				prev->next = *i;
		}
	}
	*j = (*j)->next;
}

void		ft_mapsort_bykey(t_map **map,
		int (*cmp)(const t_data *, const t_data *))
{
	t_map	*i;
	t_map	*j;
	t_map	*prev;

	if (!map || !*map || !(*map)->next || !cmp)
		return ;
	j = *map;
	while (j->next)
		my_sort(map, &j, NULL, cmp);
	prev = *map;
	i = prev->next;
	while (i)
	{
		j = i;
		while (j->next)
			my_sort(&i, &j, prev, cmp);
		prev = prev->next;
		i = prev->next;
	}
}
