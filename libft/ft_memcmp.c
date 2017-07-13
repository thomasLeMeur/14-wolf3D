/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:51 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:23 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (s1 - s2);
	i = 0;
	while (i < n && ((t_uchar*)s1)[i] - ((t_uchar*)s2)[i] == 0)
		i++;
	if (i == n)
		return (0);
	return (((t_uchar*)s1)[i] - ((t_uchar*)s2)[i]);
}
