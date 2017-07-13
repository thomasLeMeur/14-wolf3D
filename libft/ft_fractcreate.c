/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:07 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fract	ft_fractcreate(int top, int bottom)
{
	t_fract	tmp;

	tmp.top = FT_ABS(top);
	tmp.bottom = FT_ABS(bottom);
	tmp.sig = top * bottom / FT_ABS(top * bottom);
	return (tmp);
}
