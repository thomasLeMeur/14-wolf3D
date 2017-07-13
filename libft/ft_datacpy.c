/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datacpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:40 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_datacpy(t_data *a, t_data *b)
{
	if (!a || !b)
		return (a);
	if ((a = (t_data*)ft_memrealloc(a, a->data_size, b->data_size)))
	{
		a->data_size = b->data_size;
		ft_memcpy(a->data, b->data, a->data_size);
	}
	return (a);
}
