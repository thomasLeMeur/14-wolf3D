/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapmodify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:29 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapmodify(t_map *map, t_data *key, t_data *value)
{
	t_map	*tmp;
	t_data	*data;

	if (!map || !key || !value || !value->data || !value->data_size)
		return ;
	if (!(tmp = ft_mapitem_bykey(map, key)))
		return ;
	if (!(data = ft_datadup(value)))
		return ;
	if (tmp->value)
		free(tmp->value);
	tmp->value = data;
}
