/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_map	*other_before_map(t_map **map, t_map **other, t_map **i)
{
	t_map	*tmp;

	*i = *map;
	if (ft_datacmp((*i)->key, (*other)->key) > 0)
	{
		*map = *other;
		*other = (*other)->next;
		(*map)->next = *i;
	}
	tmp = *map;
	while (*other && ft_datacmp((*i)->key, (*other)->key) > 0)
	{
		tmp->next = *other;
		*other = (*other)->next;
		tmp = tmp->next;
	}
	if (*i == tmp)
		*i = (*i)->next;
	return (tmp);
}

static void		next_step(t_map **tmp, t_map **i)
{
	(*tmp)->next = *i;
	*i = (*i)->next;
}

void			ft_mapmerge(t_map **map, t_map *other)
{
	t_map	*i;
	t_map	*tmp;

	if (!map || !other)
		return ((void)((map && !*map) ? (*map = other) : 0));
	tmp = other_before_map(map, &other, &i);
	while (i && other)
	{
		if (ft_datacmp(i->key, other->key) > 0)
		{
			if (ft_datacmp(tmp->key, other->key) != 0)
				tmp->next = other;
			else
				next_step(&tmp, &i);
			other = other->next;
		}
		else
			next_step(&tmp, &i);
		tmp = tmp->next;
	}
	if (!i)
		while (other && ft_datacmp(tmp->key, other->key) == 0)
			other = other->next;
	tmp->next = (!other) ? i : other;
}
