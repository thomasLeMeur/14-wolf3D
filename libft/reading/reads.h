/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:17:20 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/08 20:14:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READS_H
# define READS_H

# include "../ft_printf.h"
# include "../libft.h"

int		conv_ind1(char c, t_printf_arg *arg);
int		attr_chars(char c, t_printf_arg *arg);
size_t	eval_arg(char *text, t_printf_arg *arg);
void	check_cs(t_printf_arg *arg, va_list *ap);
void	check_bin(t_printf_arg *arg, va_list *ap);
void	check_dioux(t_printf_arg *arg, va_list *ap);
int		long_modif(char c, char next, t_printf_arg *arg);
int		create_wtongbuf(char *text, size_t len, t_printf_arg *arg);
int		width_and_prec(char c, char *text, t_printf_arg *arg, int len);
size_t	read_arg(char *text, t_printf_arg *arg, va_list *ap, int first);
int		fill_buf(t_printf_arg *arg, va_list *ap, char *text, size_t *len);

#endif
