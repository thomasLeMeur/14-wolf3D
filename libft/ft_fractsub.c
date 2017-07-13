/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:57 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fract	ft_fractsub(t_fract a, t_fract b)
{
	int		tmp;
	int		coeff1;
	int		coeff2;
	t_fract	result;

	result.sig = 1;
	result.bottom = ft_ppcm(a.bottom, b.bottom);
	coeff1 = result.bottom / a.bottom;
	coeff2 = result.bottom / b.bottom;
	tmp = (int)(a.top * coeff1 * a.sig) - (int)(b.top * coeff2 * b.sig);
	if (tmp < 0)
	{
		result.sig = -1;
		result.top = -tmp;
	}
	else
		result.top = tmp;
	return (ft_fractsimplify(result));
}
