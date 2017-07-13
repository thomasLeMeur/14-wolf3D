/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:01 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:38 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;

	if (dest && src)
	{
		i = ft_strlen(dest);
		while (*src)
			dest[i++] = *(src++);
		dest[i] = '\0';
	}
	return (dest);
}
