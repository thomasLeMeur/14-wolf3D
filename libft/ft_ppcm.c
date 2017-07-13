/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:41 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:57:30 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ppcm(unsigned int a, unsigned int b)
{
	unsigned long long	tmp;

	tmp = (unsigned long long)a * (unsigned long long)b;
	return ((!b) ? 0 : tmp / ft_pgcd(a, b));
}
