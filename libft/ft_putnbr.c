/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 15:58:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	long	div;

	if (!n)
		return (ft_putchar('0'));
	div = 1;
	nb = (n < 0) ? -(long)n : n;
	if (n < 0)
		ft_putchar('-');
	div = 1;
	while (div * 10 <= nb)
		div *= 10;
	while (div)
	{
		ft_putchar('0' + nb / div);
		nb %= div;
		div /= 10;
	}
}
