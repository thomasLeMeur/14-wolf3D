/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractmul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:56 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fract	ft_fractmul(t_fract a, t_fract b)
{
	int		tmp;
	t_fract	result;

	result.sig = 1;
	tmp = a.top * a.sig * b.top * b.sig;
	result.bottom = a.bottom * b.bottom;
	if (tmp < 0)
	{
		result.sig = -1;
		result.top = -tmp;
	}
	else
		result.top = tmp;
	return (ft_fractsimplify(result));
}
