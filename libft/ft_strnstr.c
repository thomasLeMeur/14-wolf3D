/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/26 13:59:46 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *target, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	s1;
	size_t	s2;

	if (!s || !target)
		return (NULL);
	s1 = ft_strlen(s);
	if (!(s2 = ft_strlen(target)))
		return ((char*)s);
	i = -1;
	while (s[++i] && i < n)
		if (s[i] == *target)
		{
			j = 1;
			k = i + j;
			while (j < s2 && k < s1 && k < n && s[k] == target[j])
				k = i + (++j);
			if (j == s2)
				return ((char*)s + i);
		}
	return (NULL);
}
