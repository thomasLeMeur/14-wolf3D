/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractsimplify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:56 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fract	ft_fractsimplify(t_fract a)
{
	int		pgcd;
	t_fract	result;

	pgcd = ft_pgcd(a.top, a.bottom);
	result.top = a.top / pgcd;
	result.bottom = a.bottom / pgcd;
	result.sig = a.sig;
	return (result);
}
