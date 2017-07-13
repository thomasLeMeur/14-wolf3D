/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:06:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 14:59:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

typedef struct	s_printf_prec
{
	int	left;
	int	right;
	int	id_arg;
}				t_printf_prec;

enum			e_printf_flags
{
	conv = 1,
	zero = 2,
	less = 4,
	space = 8,
	plus = 16,
	quote = 32,
	any = 64,
	hh = 128,
	h = 256,
	l = 512,
	ll = 1024,
	j = 2048,
	z = 4096,
	deci = 8192,
	p = 16384,
	b = 32768
};

enum			e_printf_convs
{
	di = 1,
	o = 2,
	u = 4,
	x = 8,
	X = 16,
	e = 32,
	E = 64,
	f = 128,
	F = 256,
	c = 512,
	s = 1024,
	Y = 2048
};

typedef struct	s_printf_arg
{
	char				*buf;
	enum e_printf_convs	conv;
	enum e_printf_flags	flags;
	t_printf_prec		prec;
	size_t				size;
}				t_printf_arg;

int				ft_printf(char *fmt, ...);

#endif
