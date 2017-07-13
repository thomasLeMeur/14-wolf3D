/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:02 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_before_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

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

t_list			*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	t_list	*add;
	char	*tmp;
	int		word_size;

	if (!s)
		return (NULL);
	lst = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(word_size = size_before_c(s, c)))
			break ;
		if (!(tmp = ft_strnew(word_size)))
			return (free_lst(lst));
		tmp = ft_strncpy(tmp, s, word_size);
		if (!(add = ft_lstnew(tmp, word_size)))
			return (free_lst(lst));
		ft_lstpush(&lst, add);
		s += word_size;
	}
	return (lst);
}
