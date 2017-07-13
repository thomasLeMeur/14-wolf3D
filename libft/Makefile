# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 18:11:41 by tle-meur          #+#    #+#              #
#    Updated: 2016/05/25 14:25:31 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
			ft_tolower.c ft_toupper.c ft_gnl.c ft_gnlmulti.c \
			ft_memdup.c ft_putbin.c ft_tabclr.c ft_tabset.c ft_tabiter.c \
			ft_tabmap.c ft_tabsort.c ft_lstsize.c ft_lstrev.c ft_lstpop.c \
			ft_lstlast.c ft_lstdequeue.c ft_lstfrom_string_tab.c \
			ft_lstat.c ft_lstsplit.c ft_lstcat.c ft_lstenqueue.c \
			ft_lstpush.c ft_lstsort.c ft_lstfrom_void_tab.c ft_lstfind.c \
			ft_lstinsert.c ft_lstfrom_btree_infix.c ft_itoa_base.c \
			ft_lstfrom_btree_prefix.c ft_lstfrom_btree_suffix.c \
			ft_lstfrom_btree_bylevel_up.c ft_lstfrom_btree_bylevel_down.c \
			ft_btreerev.c ft_btreesize.c ft_btreedepth.c ft_btreenew.c \
			ft_btreedel.c ft_btreeiter_infix.c ft_btreeiter_prefix.c \
			ft_btreeiter_suffix.c ft_btreeiter_bylevel_up.c \
			ft_btreemap_infix.c ft_btreemap_prefix.c ft_btreemap_suffix.c \
			ft_btreeiter_bylevel_down.c ft_btreesort_infix.c \
			ft_btreesort_prefix.c ft_btreesort_suffix.c \
			ft_btreesort_bylevel_up.c ft_btreesort_bylevel_down.c \
			ft_btreemerge.c ft_btreefind_infix.c ft_btreefind_prefix.c \
			ft_btreefind_suffix.c ft_btreefind_bylevel_up.c \
			ft_btreefind_bylevel_down.c ft_itoa_base.c ft_strrev.c \
			ft_lstfrom_mapkeys_byvalue.c ft_btreefrom_map.c ft_mapnew.c \
			ft_mapsize.c ft_mapdel.c ft_maplast.c ft_mapdelone.c \
			ft_mapmerge.c ft_mapmodify.c ft_mapdel_bykey.c \
			ft_mapsort_bykey.c ft_mapitem_bykey.c ft_mapiter.c \
			ft_mapsort_byvalue.c ft_mapvalue_bykey.c \
			ft_mapdelall_byvalue.c ft_mapdellast_byvalue.c ft_mapadd.c \
			ft_mapdelfirst_byvalue.c ft_mapkey_byvalue_last.c \
			ft_mapkey_byvalue_first.c ft_mapitem_byvalue_last.c \
			ft_mapitem_byvalue_first.c ft_mapmap.c ft_memequ.c \
			ft_datadel.c ft_datadup.c ft_datacmp.c ft_dataequ.c \
			ft_datacpy.c ft_datanew.c ft_memrealloc.c ft_lstmerge.c \
			ft_btreeadd.c ft_btreedelone.c ft_datatmp.c ft_pgcd.c \
			ft_fractadd.c ft_fractsub.c ft_fractmul.c \
			ft_fractdiv.c ft_fractsimplify.c ft_ppcm.c \
			ft_fractcreate.c ft_printf.c ft_tabdel.c ft_sprintf.c \
			ft_printf_fd.c ft_isnumber.c

SRCSWR	=	writes/ft_itoas_bases.c writes/space_chars.c writes/utilities.c \
			writes/write_doubles.c writes/write_scientist.c writes/write_extra.c

SRCSRD	=	reading/check_arg.c reading/check_cs.c reading/check_dioux.c \
			reading/check_format.c reading/check_bin.c reading/fill.c

OBJS	=	$(SRCS:.c=.o) $(SRCSWR:.c=.o) $(SRCSRD:.c=.o)


all		:	$(NAME)

%.o		:	%.c
			@gcc $(FLAGS) -o $@ -c $<

$(NAME)	:	$(OBJS)
			@gcc $(FLAGS) -c $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean $(NAME)

simple	:	re
			@rm -f $(OBJS)

.PHONY:		all clean fclean re simple
