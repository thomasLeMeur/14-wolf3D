/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_string_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}

t_list		*ft_lstfrom_string_tab(char **tab)
{
	int		i;
	t_list	*lst;
	t_list	*add;
	char	*tmp;

	if (!tab || !*tab)
		return (NULL);
	i = -1;
	lst = NULL;
	while (tab[++i])
	{
		if (!(tmp = ft_strdup(tab[i])))
		{
			ft_lstdel(&lst, &del);
			break ;
		}
		if (!(add = ft_lstnew(tmp, ft_strlen(tmp))))
		{
			ft_lstdel(&lst, &del);
			break ;
		}
		ft_lstpush(&lst, add);
	}
	return (lst);
}
