/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:06:59 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/08 20:17:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"
#include "reading/reads.h"
#include "writes/writes.h"

static int	close_and_quit(va_list *ap, int code)
{
	va_end(*ap);
	return (code);
}

static int	check_normal_text(char *text, char **buf, size_t *size,
				size_t *i)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (text[len] && text[len] != '%')
		len++;
	if (len)
	{
		if (!(tmp = (char *)ft_memrealloc(*buf, *size, *size + len)))
			return (freeptrs_and_quit(-1, 1, buf));
		*buf = tmp;
		if (!ft_memcpy(*buf + *size, text, len))
			return (freeptrs_and_quit(-1, 1, buf));
		*size += len;
		*i += len;
	}
	return (1);
}

static int	check_arg_text(char *text, char **buf, size_t *size,
				va_list *ap)
{
	t_printf_arg	arg;
	int				len;
	char			*tmp;

	if ((len = read_arg(text, &arg, ap, 1)) == -1)
		return (-1);
	if (arg.size)
	{
		if (!(tmp = (char *)ft_memrealloc(*buf, *size, *size + arg.size)))
			return (freeptrs_and_quit(-1, 1, &arg.buf));
		*buf = tmp;
		if (!ft_memcpy(*buf + *size, arg.buf, arg.size))
			return (freeptrs_and_quit(-1, 1, &arg.buf));
		*size += arg.size;
	}
	ft_memdel((void **)(&arg.buf));
	return (len);
}

int			ft_printf(char *fmt, ...)
{
	va_list			ap;
	char			*buf;
	size_t			i;
	int				len;
	size_t			size;

	if (!fmt)
		return (-1);
	i = 0;
	size = 0;
	buf = NULL;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (check_normal_text(&fmt[i], &buf, &size, &i) == -1)
			return (close_and_quit(&ap, -1) && freeptrs_and_quit(-1, 1, &buf));
		if (!fmt[i])
			break ;
		if ((len = check_arg_text(&fmt[++i], &buf, &size, &ap)) == -1)
			return (close_and_quit(&ap, -1) && freeptrs_and_quit(-1, 1, &buf));
		i += len;
	}
	write(1, buf, size);
	ft_memdel((void **)&buf);
	return (close_and_quit(&ap, size));
}
