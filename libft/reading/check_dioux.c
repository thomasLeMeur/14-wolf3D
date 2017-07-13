/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:11:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/30 15:17:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"
#include "../writes/writes.h"

static void	check_di(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_signed(va_arg(*ap, intmax_t), 10, arg);
	else if (arg->flags & ll)
		writes_itoa_base_signed(va_arg(*ap, long long), 10, arg);
	else if (arg->flags & l)
		writes_itoa_base_signed(va_arg(*ap, long), 10, arg);
	else if (arg->flags & z)
		writes_itoa_base_signed(va_arg(*ap, ssize_t), 10, arg);
	else if (arg->flags & h)
		writes_itoa_base_signed((short)va_arg(*ap, int), 10, arg);
	else if (arg->flags & hh)
		writes_itoa_base_signed((char)va_arg(*ap, int), 10, arg);
	else
		writes_itoa_base_signed(va_arg(*ap, int), 10, arg);
}

static void	check_o(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_unsigned(va_arg(*ap, uintmax_t), 8, arg);
	else if (arg->flags & ll)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long long), 8, arg);
	else if (arg->flags & l)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long), 8, arg);
	else if (arg->flags & z)
		writes_itoa_base_unsigned(va_arg(*ap, size_t), 8, arg);
	else if (arg->flags & h)
		writes_itoa_base_unsigned((unsigned short)va_arg(*ap, unsigned int), 8,
				arg);
	else if (arg->flags & hh)
		writes_itoa_base_unsigned((unsigned char)va_arg(*ap, unsigned int),
				8, arg);
	else
		writes_itoa_base_unsigned(va_arg(*ap, unsigned int), 8, arg);
}

static void	check_u(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_unsigned(va_arg(*ap, uintmax_t), 10, arg);
	else if (arg->flags & ll)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long long), 10, arg);
	else if (arg->flags & l)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long), 10, arg);
	else if (arg->flags & z)
		writes_itoa_base_unsigned(va_arg(*ap, size_t), 10, arg);
	else if (arg->flags & h)
		writes_itoa_base_unsigned((unsigned short)va_arg(*ap, unsigned int),
				10, arg);
	else if (arg->flags & hh)
		writes_itoa_base_unsigned((unsigned char)va_arg(*ap, unsigned int),
				10, arg);
	else
		writes_itoa_base_unsigned(va_arg(*ap, unsigned int), 10, arg);
}

static void	check_x(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_unsigned(va_arg(*ap, uintmax_t), 16, arg);
	else if (arg->flags & ll)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long long), 16, arg);
	else if (arg->flags & l)
		writes_itoa_base_unsigned(va_arg(*ap, unsigned long), 16, arg);
	else if (arg->flags & z)
		writes_itoa_base_unsigned(va_arg(*ap, size_t), 16, arg);
	else if (arg->flags & h)
		writes_itoa_base_unsigned((unsigned short)va_arg(*ap, unsigned int),
				16, arg);
	else if (arg->flags & hh)
		writes_itoa_base_unsigned((unsigned char)va_arg(*ap, unsigned int),
				16, arg);
	else
		writes_itoa_base_unsigned(va_arg(*ap, unsigned int), 16, arg);
}

void		check_dioux(t_printf_arg *arg, va_list *ap)
{
	if (arg->conv & di)
		check_di(arg, ap);
	else if (arg->conv & o)
		check_o(arg, ap);
	else if (arg->conv & u)
		check_u(arg, ap);
	else if (arg->conv & x || arg->conv & X)
		check_x(arg, ap);
}
