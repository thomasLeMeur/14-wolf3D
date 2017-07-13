/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:54 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:58:04 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabsort(void *tab, size_t tab_size, size_t content_size,
		int (*cmp)(const void *, const void *, size_t))
{
	size_t	i;
	size_t	j;
	void	*addr1;
	void	*addr2;
	size_t	size;

	if (!tab || !content_size || !cmp)
		return ;
	i = 0;
	size = tab_size / content_size;
	while (i < size)
	{
		j = i + 1;
		addr1 = tab + i++ * content_size;
		while (j < size)
		{
			addr2 = tab + j++ * content_size;
			if ((*cmp)(addr1, addr2, content_size))
				FT_SWAP(addr1, addr2, void *);
		}
	}
}
