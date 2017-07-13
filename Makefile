# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/06/01 14:32:24 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

CC		=	gcc

FLAGS	=	-g -Wall -Wextra -Werror -O3

SRCS	=	main.c init_and_quit.c parser.c image.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) $(FLAGS) -o $@ -c $< -I libft/

$(NAME)	:	$(OBJS)
			@make -C libft/
			@echo "libft created"
			@$(CC) $(FLAGS) -o $@ $^ -L libft -lft -lpthread -lm \
				-lSDL_mixer -lSDL
				#-lmlx -framework OpenGL -framework AppKit
			@echo "$(NAME) created"

clean	:
			@rm -f $(OBJS)
			@echo "objects deleted"

fclean	:	clean
			@rm -f $(NAME)
			@make -C libft/ fclean
			@echo "$(NAME) and libft deleted"

re		:	fclean $(NAME)

simple	:	re
			@rm -f $(OBJS)
			@echo "objects deleted"

update	:	clean all

.PHONY	:	all clean fclean re simple update
