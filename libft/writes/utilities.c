/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:25:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 14:50:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"
#include <stdarg.h>

void	my_strrev(char *buf, int size)
{
	int	i;
	int	j;

	i = -1;
	j = size;
	size /= 2;
	while (++i < size && --j)
		FT_SWAP(buf[i], buf[j], int);
}

size_t	freeptrs_and_quit(size_t code, int nb, ...)
{
	va_list	ap;
	int		i;
	char	**ptr;

	i = 0;
	va_start(ap, nb);
	while (i++ < nb)
	{
		ptr = va_arg(ap, char **);
		ft_memdel((void **)ptr);
	}
	va_end(ap);
	return (code);
}

int		create_wrongbuf(char *text, size_t len, t_printf_arg *arg)
{
	size_t	i;

	arg->size = FT_MAX(arg->prec.left, 1);
	if (!(arg->buf = ft_strnew(arg->size)))
		return (0);
	if (!text[len])
		return ((arg->size = 0));
	i = 0;
	if (!(arg->flags & less))
		while (i < arg->size - 1)
			arg->buf[i++] = (arg->flags & zero) ? '0' : ' ';
	arg->buf[i++] = (arg->flags & deci && arg->flags & any) ? '*' : text[len];
	while (i < arg->size)
		arg->buf[i++] = ' ';
	return (1);
}

size_t	ft_wstrlen(const wchar_t *s, int index, int max)
{
	int		i;
	int		add;
	size_t	size;

	i = -1;
	size = 0;
	if (s)
		while (++i < index && (int)size < max)
		{
			if (s[i] <= 0x7F)
				add = 1;
			else if (s[i] <= 0x7FF)
				add = 2;
			else if (s[i] <= 0xFFFF)
				add = 3;
			else if (s[i] <= 0x10FFFF)
				add = 4;
			if ((int)size + add > max)
				break ;
			size += add;
		}
	return (size);
}

void	add_char(wchar_t c, t_printf_arg *arg)
{
	if (c <= 0x7F)
		arg->buf[arg->size++] = (char)c;
	else if (c <= 0x7FF)
	{
		arg->buf[arg->size++] = (char)((c >> 6) + 0xC0);
		arg->buf[arg->size++] = (char)((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		arg->buf[arg->size++] = (char)((c >> 12) + 0xE0);
		arg->buf[arg->size++] = (char)(((c >> 6) & 0x3F) + 0x80);
		arg->buf[arg->size++] = (char)((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		arg->buf[arg->size++] = (char)((c >> 18) + 0xF0);
		arg->buf[arg->size++] = (char)(((c >> 12) & 0x3F) + 0x80);
		arg->buf[arg->size++] = (char)(((c >> 6) & 0x3F) + 0x80);
		arg->buf[arg->size++] = (char)((c & 0x3F) + 0x80);
	}
}
