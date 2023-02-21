# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:57:57 by orfreoua          #+#    #+#              #
#    Updated: 2023/02/21 04:02:22 by ojauregu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS			=	srcs/*.c\
					srcs/libft/*.c\
					srcs/parsing/*.c\
					srcs/minimap/*.c\
					srcs/draw/*.c\
					srcs/raycasting/*.c\
					

DIR_MLX			=	./mlx_linux/

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I ./headers

LIBS			= -L ./mlx_linux/ -lmlx -lXext -lX11 -lm

RM				= rm -f

all:		${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:c=o}

$(NAME):	$(OBJS)
				make -C $(DIR_MLX)
				${CC} $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
				make -C $(DIR_MLX) clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: clean all

.PHONY:		all clean fclean re
