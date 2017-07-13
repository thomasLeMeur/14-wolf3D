/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:24 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	i = 0;
	if ((tmp = ft_strnew(ft_strlen(s))))
		while (*s)
			tmp[i++] = (*f)(*(s++));
	return (tmp);
}
