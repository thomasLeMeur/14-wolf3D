/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbin(void *val, size_t size)
{
	size_t	i;
	t_uchar	tmp;

	if (!val)
		return ;
	while (size)
	{
		i = 256;
		tmp = *(t_uchar*)(val + --size);
		while ((i >>= 1))
		{
			ft_putchar('0' + tmp / i);
			tmp -= (tmp / i) * i;
		}
	}
}
