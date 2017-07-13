/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_mapkeys_byvalue.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:41 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:43 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_mapkeys_byvalue(t_map *map, t_data *value)
{
	t_data	tmp;
	t_list	*lst;
	t_list	*add;

	if (!value)
		return (NULL);
	lst = NULL;
	while (map)
	{
		tmp.data = ((t_list*)map->value)->content;
		tmp.data_size = ((t_list*)map->value)->content_size;
		if (!ft_datacmp(value, &tmp))
		{
			add = (t_list*)map->key;
			add = ft_lstnew(add->content, add->content_size);
			ft_lstpush(&lst, add);
		}
		map = map->next;
	}
	return (lst);
}
