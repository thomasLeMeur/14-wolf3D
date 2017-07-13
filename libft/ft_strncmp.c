/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (s1 - s2);
	if (!n)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && (t_uchar)s1[i] == (t_uchar)s2[i])
		i++;
	if (i == n)
		i--;
	return ((t_uchar)s1[i] - (t_uchar)s2[i]);
}
