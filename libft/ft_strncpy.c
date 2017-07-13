/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:29 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest && src)
	{
		while (i < n && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
			dest[i++] = '\0';
	}
	return (dest);
}
