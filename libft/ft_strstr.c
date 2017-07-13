/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:42 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:58 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *target)
{
	int	i;
	int	j;
	int	k;
	int	s1;
	int	s2;

	if (!s || !target)
		return (NULL);
	s1 = ft_strlen(s);
	if (!(s2 = ft_strlen(target)))
		return ((char*)s);
	i = -1;
	while (s[++i])
		if (s[i] == *target)
		{
			j = 1;
			k = i + j;
			while (k < s1 && j < s2 && s[k] == target[j])
				k = i + (++j);
			if (j == s2)
				return ((char*)s + i);
		}
	return (NULL);
}
