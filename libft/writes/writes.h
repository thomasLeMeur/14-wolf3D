/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:22:08 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/08 20:14:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITES_H
# define WRITES_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include "../libft.h"
# include "../ft_printf.h"

/*
**	Utilities
*/
void			my_strrev(char *buf, int size);
void			add_char(wchar_t c, t_printf_arg *arg);
size_t			freeptrs_and_quit(size_t code, int nb, ...);
size_t			ft_wstrlen(const wchar_t *s, int index, int max);
int				create_wrongbuf(char *text, size_t len, t_printf_arg *arg);

/*
**	Write signed and unsigned integers
*/
void			writes_itoa_base_signed(intmax_t nb, int base,
				t_printf_arg *arg);
void			writes_itoa_base_unsigned(uintmax_t nb, int base,
				t_printf_arg *arg);

/*
**	Write (space) char and string
*/
void			writes_wintt(wchar_t nb, t_printf_arg *arg);
void			writes_str(const char *s, t_printf_arg *arg);
void			writes_uchar(unsigned char c, t_printf_arg *arg);
void			writes_wstr(const wchar_t *s, t_printf_arg *arg);

/*
**	Write floating numbers
*/
typedef union	u_nb
{
	double				d;
	unsigned long long	l;
}				t_nb;

void			writes_double(double nb, t_printf_arg *arg);
void			writes_double_sc(double nb, t_printf_arg *arg);

/*
**	Write extra printing
*/
void			writes_extra(t_printf_arg *arg);
void			writes_itoa_base_binary(t_printf_arg *arg, intmax_t nb,
				size_t size);

#endif
