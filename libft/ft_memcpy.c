/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	ad1;
	size_t	ad2;
	void	*tmp;
	size_t	i;

	if (!dest || !src || !n)
		return (dest);
	tmp = &src;
	ad1 = *((size_t*)tmp);
	tmp = &dest;
	ad2 = *((size_t*)tmp);
	if ((ad1 <= ad2 && ad1 + n >= ad2) || (ad2 <= ad1 && ad2 + n >= ad1))
		return (ft_memmove(dest, src, n));
	i = 0;
	while (i < n)
	{
		((t_uchar*)dest)[i] = ((t_uchar*)src)[i];
		i++;
	}
	return (dest);
}
