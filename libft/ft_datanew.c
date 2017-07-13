/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datanew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:46 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:04 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_datanew(void *data, size_t data_size)
{
	t_data	*add;

	if (!data || !data_size)
		return (NULL);
	if (!(add = (t_data*)malloc(sizeof(t_data*))))
		return (NULL);
	if (!(add->data = ft_memdup(data, data_size)))
	{
		free(add);
		return (NULL);
	}
	add->data_size = data_size;
	return (add);
}
