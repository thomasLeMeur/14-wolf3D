/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:04:49 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 15:04:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	size = ft_strlen(str);
	if (!(tmp = ft_memalloc((size + 1) * sizeof(char))))
		return (NULL);
	if (!(ft_memcpy(tmp, str, size)))
		return (NULL);
	i = -1;
	j = size;
	while (j-- && ++i < size / 2)
		FT_SWAP(tmp[i], tmp[j], char);
	return (tmp);
}
