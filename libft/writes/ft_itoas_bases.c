/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:00:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/29 11:42:47 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

static void	fill_with_flags_and_reverse_buf_signed(intmax_t nb, int base,
		size_t i, t_printf_arg *arg)
{
	size_t	size;

	size = (arg->flags & zero && !(arg->flags & deci)) ? FT_MAX((int)i,
	arg->prec.left - (base == 10 && (nb < 0 || (nb >= 0 && arg->flags & plus)))
	- (nb >= 0 && arg->flags & space)) : FT_MAX((int)i, arg->prec.right);
	if (arg->flags & zero && !(arg->flags & deci) && !(arg->flags & less))
		while (i < size)
			arg->buf[i++] = '0';
	else if (arg->flags & deci)
		while (i < size)
			arg->buf[i++] = '0';
	if (base == 10 && nb < 0)
		arg->buf[i++] = '-';
	else if (base == 10 && nb >= 0 && arg->flags & plus)
		arg->buf[i++] = '+';
	else if (nb >= 0 && arg->flags & space)
		arg->buf[i++] = ' ';
	if (!(arg->flags & less))
		while ((int)i < arg->prec.left)
			arg->buf[i++] = ' ';
	my_strrev(arg->buf, i);
	if (arg->flags & less)
		while (i < arg->size)
			arg->buf[i++] = ' ';
	arg->size = i;
}

void		writes_itoa_base_signed(intmax_t nb, int base, t_printf_arg *arg)
{
	int			i;
	intmax_t	tmp;
	static char	basis[16] = "0123456789abcdef";

	arg->size = FT_MAX(arg->prec.left, arg->prec.right);
	if (!(arg->buf = ft_strnew(25 + arg->size)))
		return ;
	if (!(i = 0) && !nb)
	{
		if (arg->prec.right)
			arg->buf[i++] = '0';
		return (fill_with_flags_and_reverse_buf_signed(nb, base, i, arg));
	}
	if ((tmp = nb) < 0)
	{
		arg->buf[i++] = basis[-(tmp % base)];
		tmp = -(nb / base);
	}
	while (tmp)
	{
		arg->buf[i++] = basis[tmp % base];
		tmp /= base;
	}
	fill_with_flags_and_reverse_buf_signed(nb, base, i, arg);
}

static void	fill_with_flags_and_reverse_buf_unsigned(uintmax_t nb, size_t i,
			size_t size, t_printf_arg *a)
{
	size = (a->flags & zero && !(a->flags & deci)) ? FT_MAX((int)i,
	a->prec.left - (a->flags & conv && (a->conv & x || a->conv & X)) * 2) :
	FT_MAX((int)(i + (a->flags & conv && nb && !(a->flags & p))),
	a->prec.right);
	if (a->flags & zero && !(a->flags & deci) && !(a->flags & less))
		while (i < size)
			a->buf[i++] = '0';
	else if (a->flags & deci)
		while (i < size)
			a->buf[i++] = '0';
	else if ((i < size || i < a->size) && a->conv & o && a->flags & conv && nb)
		a->buf[i++] = '0';
	if ((a->conv & x || a->conv & X) && a->flags & conv && (nb || a->flags & l))
	{
		a->buf[i++] = (a->conv & x) ? 'x' : 'X';
		a->buf[i++] = '0';
	}
	if (!(a->flags & less))
		while ((int)i < a->prec.left)
			a->buf[i++] = ' ';
	my_strrev(a->buf, i);
	if (a->flags & less)
		while (i < a->size)
			a->buf[i++] = ' ';
	a->size = i;
}

void		writes_itoa_base_unsigned(uintmax_t nb, int base,
			t_printf_arg *arg)
{
	int			i;
	uintmax_t	tmp;
	static char	basemin[16] = "0123456789abcdef";
	static char	basemaj[16] = "0123456789ABCDEF";

	arg->size = FT_MAX(arg->prec.left, arg->prec.right);
	if (!(arg->buf = ft_strnew(25 + arg->size)))
		return ;
	tmp = nb;
	if (!(i = 0) && !nb)
	{
		if (arg->prec.right || (arg->conv & o && arg->flags & conv))
			arg->buf[i++] = '0';
		return (fill_with_flags_and_reverse_buf_unsigned(nb, i, 0, arg));
	}
	while (nb)
	{
		if (arg->conv & X)
			arg->buf[i++] = basemaj[nb % base];
		else
			arg->buf[i++] = basemin[nb % base];
		nb /= base;
	}
	fill_with_flags_and_reverse_buf_unsigned(tmp, i, 0, arg);
}
