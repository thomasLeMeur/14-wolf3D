/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:03:59 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 15:04:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nb, int base)
{
	int			i;
	int			n;
	char		tmp[33];
	static char	basis[36] = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (base < 2 || base > 36)
		return (NULL);
	if (!nb)
		return (ft_strdup("0"));
	i = 0;
	if (!(ft_memset(tmp, 0, 33)))
		return (NULL);
	if ((n = nb) && nb < 0)
	{
		tmp[i++] = basis[-(n % base)];
		n = -(n / base);
	}
	while (n)
	{
		tmp[i++] = basis[n % base];
		n /= base;
	}
	if (nb < 0 && base == 10)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}
