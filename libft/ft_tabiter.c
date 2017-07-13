/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:49 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:58:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter(void *tab, size_t tab_size, size_t content_size,
		void (*f)(void *, size_t))
{
	size_t	size;

	if (!tab || !content_size || !f)
		return ;
	size = tab_size / content_size;
	while (size)
		(*f)(tab + --size * content_size, content_size);
}
