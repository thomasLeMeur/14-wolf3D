/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:52:41 by tle-meur          #+#    #+#             */
/*   Updated: 2016/05/25 13:15:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nb_words(char const *s, char c)
{
	int	nb;

	nb = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			nb++;
		while (*s && *s != c)
			s++;
	}
	return (nb);
}

static int	size_before_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_tab(char ***tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_strdel(&((*tab)[i++]));
	free(*tab);
	return ((*tab = NULL));
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tmp;
	int		nb_words;
	int		word_size;

	if (!s)
		return (NULL);
	nb_words = count_nb_words(s, c);
	if ((tmp = (char**)malloc((nb_words + 1) * sizeof(char*))))
	{
		i = -1;
		while (++i < nb_words)
		{
			while (*s && *s == c)
				s++;
			word_size = size_before_c(s, c);
			if (!(tmp[i] = ft_strnew(word_size)))
				return (free_tab(&tmp, i));
			tmp[i] = ft_strncpy(tmp[i], s, word_size);
			s += word_size;
		}
		tmp[i] = NULL;
	}
	return (tmp);
}
