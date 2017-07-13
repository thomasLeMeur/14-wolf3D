/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:38 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s)
	{
		i = ft_strlen(s);
		if (!(char)c)
			return ((char*)(s + i));
		while (--i >= 0)
			if (s[i] == (char)c)
				return ((char*)s + i);
	}
	return (NULL);
}
