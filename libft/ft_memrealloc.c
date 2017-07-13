/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:51:37 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/23 13:33:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *s, size_t old_n, size_t new_n)
{
	t_uchar	*tmp;

	if (!new_n || old_n == new_n)
		return (s);
	if ((tmp = (t_uchar*)ft_memalloc(new_n * sizeof(t_uchar))))
	{
		old_n = (size_t)FT_MIN(old_n, new_n);
		ft_memcpy(tmp, s, old_n);
		if (s)
			free(s);
		s = tmp;
	}
	return (tmp);
}
