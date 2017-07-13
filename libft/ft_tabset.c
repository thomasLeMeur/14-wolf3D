/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:58:03 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabset(void *tab, void *val, size_t tab_size, size_t content_size)
{
	size_t	i;
	size_t	size;

	if (!tab || !val || !content_size)
		return ;
	i = 0;
	size = tab_size / content_size;
	while (i < size)
		ft_memcpy(tab + (i++ * content_size), val, content_size);
}
