/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractdiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fract	ft_fractdiv(t_fract a, t_fract b)
{
	t_fract	tmp;

	tmp.sig = b.sig;
	tmp.top = b.bottom;
	tmp.bottom = b.top;
	return (ft_fractmul(a, tmp));
}
