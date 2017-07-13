/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/06 20:07:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list*)malloc(sizeof(t_list))))
	{
		if (!(tmp->content = ft_memalloc(content_size)))
		{
			free(tmp);
			return (NULL);
		}
		if (content)
			ft_memcpy(tmp->content, content, content_size);
		else
			ft_memdel(&(tmp->content));
		tmp->content_size = (content) ? content_size : 0;
		tmp->next = NULL;
	}
	return (tmp);
}
