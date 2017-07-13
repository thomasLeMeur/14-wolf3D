/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:56:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!n || !dest || !src)
		return (NULL);
	while (i < n)
	{
		((t_uchar*)dest)[i] = ((t_uchar*)src)[i];
		if (((t_uchar*)src)[i++] == (t_uchar)c)
			break ;
	}
	return ((i == n && c) ? NULL : dest + i);
}
