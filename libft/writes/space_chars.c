/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:26:24 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 13:30:40 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "writes.h"

void		writes_wintt(wchar_t c, t_printf_arg *arg)
{
	size_t	i;
	size_t	size;
	size_t	size2;

	size = (arg->prec.right > 0) ? FT_MIN(arg->prec.right, 1) : 1;
	size2 = FT_MAX((int)size, arg->prec.left);
	i = -1;
	if (!(arg->buf = ft_strnew(size2 * 4)))
		return ;
	if (!(arg->flags & less))
	{
		while (++i < size2 - size)
			arg->buf[arg->size++] = (!(arg->flags & zero)) ? ' ' : '0';
		add_char(c, arg);
	}
	else
	{
		if (c && i++)
			add_char(c, arg);
		while (++i < size2)
			arg->buf[arg->size++] = ' ';
	}
	if (!arg->size)
		arg->size = 1;
}

void		writes_uchar(unsigned char c, t_printf_arg *arg)
{
	size_t	i;
	size_t	size;

	size = (arg->prec.right > 0) ? FT_MIN(arg->prec.right, 1) : 1;
	arg->size = FT_MAX((int)size, arg->prec.left);
	i = -1;
	if (!(arg->buf = ft_strnew(arg->size)))
		return ;
	if (!(arg->flags & less))
	{
		while (++i < arg->size - size)
			arg->buf[i] = (!(arg->flags & zero)) ? ' ' : '0';
		arg->buf[i] = c;
	}
	else
	{
		arg->buf[++i] = c;
		while (++i < arg->size)
			arg->buf[i] = ' ';
	}
	if (!arg->size)
		arg->size = 1;
}

void		writes_str(const char *s, t_printf_arg *a)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s);
	size = (a->prec.right != -1) ? FT_MIN((size_t)a->prec.right, size) : size;
	a->size = FT_MAX((int)size, a->prec.left);
	if (!(a->buf = ft_strnew(a->size)))
		return ;
	if ((i = -1) && !s && !(a->flags & deci))
		return ((void)(ft_memcpy(a->buf, "(null)", (a->size = 6))));
	if (!(j = 0) && !(a->flags & less))
	{
		while (++i < a->size - size)
			a->buf[i] = (!(a->flags & zero)) ? ' ' : '0';
		while (i < a->size)
			a->buf[i++] = s[j++];
	}
	else
	{
		while (++i < size)
			a->buf[i] = s[i];
		while (i < a->size)
			a->buf[i++] = ' ';
	}
}

static void	wstr_less_or_not(const wchar_t *str, t_printf_arg *a, size_t *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!(a->flags & less))
	{
		while (i++ < s[2] - s[3])
			a->buf[a->size++] = (!(a->flags & zero)) ? ' ' : '0';
		j = a->size;
		i = 0;
		while (i < s[1] && (!(a->flags & deci) || (s[2] = a->size - j) < s[3]))
			add_char(str[i++], a);
	}
	else
	{
		while (i < s[1])
			add_char(str[i++], a);
		while (j++ < s[2] - s[3])
			a->buf[a->size++] = ' ';
	}
}

void		writes_wstr(const wchar_t *str, t_printf_arg *arg)
{
	size_t	sizes[4];

	sizes[1] = 0;
	if (str)
		while (str[sizes[1]])
			sizes[1]++;
	sizes[3] = ft_wstrlen(str, sizes[1], INT_MAX);
	sizes[3] = (arg->prec.right != -1) ? FT_MIN((int)ft_wstrlen(str, INT_MAX,
	arg->prec.right), (int)(sizes[3])) : (int)sizes[3];
	sizes[2] = FT_MAX((int)(sizes[3]), arg->prec.left);
	if (!(arg->buf = ft_strnew(sizes[2] * 4)))
		return ;
	if (!str && !(arg->flags & deci))
		return ((void)(ft_memcpy(arg->buf, "(null)", (arg->size = 6))));
	wstr_less_or_not(str, arg, sizes);
}
