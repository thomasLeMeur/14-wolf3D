/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_void_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:44 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}

static t_list	*free_lst(t_list *lst)
{
	ft_lstdel(&lst, &del);
	return (NULL);
}

t_list			*ft_lstfrom_void_tab(const void *tab, size_t tab_size,
		size_t content_size)
{
	int		i;
	t_list	*lst;
	t_list	*add;
	char	*tmp;
	int		size;

	if (!tab || !content_size)
		return (NULL);
	i = -1;
	lst = NULL;
	size = tab_size / content_size;
	while (++i < size)
	{
		if (!(tmp = ft_strdup(tab + i * content_size)))
			return (free_lst(lst));
		if (!(add = ft_lstnew(tmp, ft_strlen(tmp))))
			return (free_lst(lst));
		ft_lstpush(&lst, add);
	}
	return (lst);
}
