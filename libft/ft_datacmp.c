/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datacmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_datacmp(const t_data *a, const t_data *b)
{
	int	size;
	int	result;

	if (!a || !b)
		return (a - b);
	size = (int)FT_MIN(a->data_size, b->data_size);
	result = ft_memcmp(a->data, b->data, size);
	return ((!result) ? (int)(a->data_size - b->data_size) : result);
}
