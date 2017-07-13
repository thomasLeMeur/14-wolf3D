/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:40 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pgcd(unsigned int a, unsigned int b)
{
	unsigned int	max;
	unsigned int	min;
	unsigned int	tmp;

	if (a < b)
	{
		max = b;
		min = a;
	}
	else
	{
		max = a;
		min = b;
	}
	while (max != 1 && min != 0)
	{
		tmp = max;
		max = min;
		min = tmp % min;
	}
	return (max);
}
