/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:43:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/29 11:43:17 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

static void	my_part3(t_printf_arg *a)
{
	ft_memset(a->buf + 1459, ' ', 34);
	ft_memcpy(a->buf + 1493, "\"\"\"\"$$$$$$$$$$$\n", 17);
	ft_memset(a->buf + 1510, ' ', 38);
	ft_memcpy(a->buf + 1548, "$$$$$$$$$$$$\n", 14);
	ft_memset(a->buf + 1562, ' ', 39);
	ft_memcpy(a->buf + 1601, "$$$$$$$$$$\"\n", 13);
	ft_memset(a->buf + 1614, ' ', 40);
	ft_memcpy(a->buf + 1654, "\"$$$\"\"\n", 8);
}

static void	my_part2(t_printf_arg *a)
{
	ft_memcpy(a->buf + 691, "    o$$\"   $$$$$$$$$$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 728, "$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o\n", 38);
	ft_memcpy(a->buf + 766, "    $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 803, "$$$$$$$$$$$$$$$$$$$\" \"$$$$$$ooooo$$$$o\n", 40);
	ft_memcpy(a->buf + 843, "   o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 880, "$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$\n", 41);
	ft_memcpy(a->buf + 921, "   $$$$$$$$\"$$$$   $$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 958, "$$$$$$$$$$$$$$$$     $$$$\"\"\"\"\"\"\"\"\n", 35);
	ft_memcpy(a->buf + 993, "  \"\"\"\"       $$$$    \"$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 1030, "$$$$$$$$$$$$$\"      o$$$\"\n", 26);
	ft_memcpy(a->buf + 1056, "             \"$$$o     \"\"\"$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 1093, "$$$$$$$\"$$\"         $$$\n", 25);
	ft_memcpy(a->buf + 1118, "               $$$o          \"$$\"\"$$$", 37);
	ft_memcpy(a->buf + 1155, "$$$\"\"\"\"           o$$$\n", 24);
	ft_memcpy(a->buf + 1179, "                $$$$o                ", 37);
	ft_memcpy(a->buf + 1216, "                o$$$\"\n", 23);
	ft_memcpy(a->buf + 1239, "                 \"$$$$o      o$$$$$$o", 37);
	ft_memcpy(a->buf + 1276, "\"$$$$o        o$$$$\n", 21);
	ft_memcpy(a->buf + 1297, "                   \"$$$$$oo     \"\"$$$", 38);
	ft_memcpy(a->buf + 1335, "$o$$$$$o   o$$$$\"\"\n", 20);
	ft_memcpy(a->buf + 1355, "                      \"\"$$$$$oooo  \"$", 37);
	ft_memcpy(a->buf + 1392, "$$o$$$$$$$$$\"\"\"\n", 17);
	ft_memset(a->buf + 1409, ' ', 26);
	ft_memcpy(a->buf + 1435, "\"\"$$$$$$$oo $$$$$$$$$$\n", 24);
	my_part3(a);
}

void		writes_extra(t_printf_arg *a)
{
	a->size = 1662;
	if (!(a->buf = ft_strnew(a->size)))
		return ((void)(a->size = 0));
	a->buf[0] = '\n';
	ft_memset(a->buf + 1, ' ', 28);
	ft_memcpy(a->buf + 29, "oooo$$$$$$$$$$$$oooo\n", 21);
	ft_memset(a->buf + 50, ' ', 24);
	ft_memcpy(a->buf + 74, "oo$$$$$$$$$$$$$$$$$$$$$$$$o\n", 28);
	ft_memcpy(a->buf + 102, "                    oo$$$$$$$$$$$$$$$$$$$$$", 43);
	ft_memcpy(a->buf + 145, "$$$$$$$$$o         o$   $$ o$\n", 30);
	ft_memcpy(a->buf + 175, "    o $ oo        o$$$$$$$$$$$$$$$$$$$$", 39);
	ft_memcpy(a->buf + 214, "$$$$$$$$$$$$$$$$o       $$ $$ $$o$\n", 35);
	ft_memcpy(a->buf + 249, " oo $ $ \"$      o$$$$$$$$$    $$$$$$$$", 39);
	ft_memcpy(a->buf + 288, "$$$$$    $$$$$$$$$o       $$$o$$o$\n", 35);
	ft_memcpy(a->buf + 323, " \"$$$$$$o$     o$$$$$$$$$      $$$$$$", 37);
	ft_memcpy(a->buf + 360, "$$$$$      $$$$$$$$$$o    $$$$$$$$\n", 35);
	ft_memcpy(a->buf + 395, "   $$$$$$$    $$$$$$$$$$$      $$$$$$", 37);
	ft_memcpy(a->buf + 432, "$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n", 35);
	ft_memcpy(a->buf + 467, "   $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$", 37);
	ft_memcpy(a->buf + 504, "$$$$$$    $$$$$$$$$$$$$$  \"\"\"$$$\n", 33);
	ft_memcpy(a->buf + 537, "    \"$$$\"\"\"\"$$$$$$$$$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 584, "$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$\n", 34);
	ft_memcpy(a->buf + 618, "     $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$", 37);
	ft_memcpy(a->buf + 655, "$$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$o\n", 36);
	my_part2(a);
}

void		writes_itoa_base_binary(t_printf_arg *arg, intmax_t nb,
			size_t size)
{
	size_t	i;
	size_t	j;

	arg->size = size * 8;
	if (!(arg->buf = ft_strnew(arg->size)))
		return ((void)(arg->size = 0));
	i = 0;
	j = arg->size - 1;
	while (i < arg->size)
		arg->buf[i++] = ((nb >> j--) & 0x1) + '0';
}
