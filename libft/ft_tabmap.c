/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:51 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:58:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_tabmap(void *tab, size_t tab_size, size_t content_size,
		void (*f)(void *, size_t))
{
	t_uchar	*add;
	size_t	size;

	if (!tab || !content_size || !f)
		return (NULL);
	size = tab_size / content_size;
	if ((add = (t_uchar*)ft_memdup(tab, tab_size)))
		while (size)
			(*f)(add + --size * content_size, content_size);
	return (add);
}
