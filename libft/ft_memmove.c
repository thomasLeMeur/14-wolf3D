/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:35 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/23 15:17:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_uchar	*tmp;

	if (!(tmp = (t_uchar *)malloc(n * sizeof(t_uchar))))
		return (dest);
	i = 0;
	if (dest && src)
	{
		while (i < n)
		{
			tmp[i] = ((t_uchar*)src)[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			((t_uchar*)dest)[i] = tmp[i];
			i++;
		}
	}
	free(tmp);
	return (dest);
}
