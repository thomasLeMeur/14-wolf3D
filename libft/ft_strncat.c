/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:27 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:50 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (dest && src)
	{
		i = 0;
		j = ft_strlen(dest);
		while (i < n && src[i])
			dest[j++] = src[i++];
		dest[j] = '\0';
	}
	return (dest);
}
