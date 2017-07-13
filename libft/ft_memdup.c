/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:31 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	t_uchar	*add;

	if (!src || !size)
		return (NULL);
	if ((add = (t_uchar*)malloc(size * sizeof(t_uchar))))
		ft_memcpy(add, src, size);
	return (add);
}
