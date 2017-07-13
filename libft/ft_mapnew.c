/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:32 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_mapnew(t_data *key, t_data *value)
{
	t_map	*add;

	if (!key || !value)
		return (NULL);
	if ((add = (t_map*)malloc(sizeof(t_map))))
	{
		if (!(add->key = ft_datadup(key)))
		{
			free(add);
			return (NULL);
		}
		if (!(add->value = ft_datadup(value)))
		{
			ft_datadel(&(add->key));
			free(add);
			return (NULL);
		}
		add->next = NULL;
	}
	return (add);
}
