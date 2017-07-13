/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:14 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:43 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*tmp;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	tmp = (char*)malloc((size + 1) * sizeof(char));
	return (ft_strncpy(tmp, s, size + 1));
}
