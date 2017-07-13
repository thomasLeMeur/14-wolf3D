/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/26 13:18:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	char	*tmp;

	if (!s)
		return (NULL);
	b = 0;
	while (s[b] && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	if (!s[b])
		return (ft_strnew(0));
	e = ft_strlen(s) - 1;
	while (e > b && (s[e] == ' ' || s[e] == '\n' || s[e] == '\t'))
		e--;
	if ((tmp = ft_strnew(e - b + 1)))
		tmp = ft_strncpy(tmp, s + b, e - b + 1);
	return (tmp);
}
