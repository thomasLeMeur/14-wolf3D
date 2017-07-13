/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:06 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (s1 - s2);
	while (s1[i] && s2[i] && (t_uchar)s1[i] == (t_uchar)s2[i])
		i++;
	return ((t_uchar)s1[i] - (t_uchar)s2[i]);
}
