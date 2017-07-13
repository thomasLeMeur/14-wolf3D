/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:55 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	div;

	div = 1;
	nb = (n < 0) ? -(long)n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	div = 1;
	while (div * 10 <= nb)
		div *= 10;
	while (div)
	{
		ft_putchar_fd('0' + nb / div, fd);
		nb %= div;
		div /= 10;
	}
}
