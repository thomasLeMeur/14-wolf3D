/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:48:19 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:16 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	long	div;
	int		size;
	char	*result;

	i = 0;
	div = 1;
	size = 0;
	nb = (n < 0) ? -(long)n : n;
	while (++size && div * 10 <= nb)
		div *= 10;
	if ((result = ft_strnew((n < 0) ? size + 1 : size)))
	{
		if (n < 0)
			result[i++] = '-';
		while (div)
		{
			result[i++] = '0' + (nb / div);
			nb %= div;
			div /= 10;
		}
	}
	return (result);
}
