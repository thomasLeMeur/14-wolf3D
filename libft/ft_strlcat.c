/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:21 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/26 16:12:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dest_size;

	src_size = 0;
	dest_size = 0;
	if (dest && src)
	{
		j = 0;
		src_size = ft_strlen(src);
		while (j < n && dest[j])
			j++;
		i = 0;
		dest_size = j;
		while (j < n - 1 && i < src_size && src[i])
			dest[j++] = src[i++];
		if (j < n)
			dest[j] = '\0';
	}
	return (src_size + dest_size);
}
