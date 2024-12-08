# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:57:57 by orfreoua          #+#    #+#              #
#    Updated: 2024/01/22 21:05:22 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUS = cub3D_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

MLX_LINUX = ./libs/mlx_linux/
MLX_MAC = ./libs/mlx_mac/
INCLUDES = ./headers/

SRCS =  srcs/parsing/utils.c\
		srcs/libft/ft_putchar_fd.c \
		srcs/libft/ft_strdup.c \
		srcs/libft/ft_strncmp.c \
		srcs/libft/ft_putnbr_fd.c \
		srcs/libft/ft_strjoin.c \
		srcs/libft/ft_substr.c \
		srcs/libft/ft_putstr_fd.c \
		srcs/libft/ft_strleen.c \
		srcs/libft/get_next_line.c \
		srcs/raycasting/raycasting.c \
		srcs/raycasting/events.c \
		srcs/raycasting/display.c \
		srcs/raycasting/shiffting.c \
		srcs/raycasting/rc_logique.c \
		srcs/raycasting/rc_utils.c \
		srcs/parsing/all_in_struct.c \
		srcs/parsing/bonus_map.c \
		srcs/parsing/bonus_map_suite.c \
		srcs/parsing/teleport.c \
		srcs/parsing/lac.c \
		srcs/parsing/maisons.c \
		srcs/parsing/free_mapy.c \
		srcs/parsing/load_fole.c \
		srcs/parsing/check_map.c \
		srcs/parsing/free_tab.c \
		srcs/parsing/malloc_one_tab.c \
		srcs/parsing/check_one.c \
		srcs/parsing/ft_itoa.c \
		srcs/parsing/pars_err.c \
		srcs/parsing/check_space_b.c \
		srcs/parsing/ft_s.c \
		srcs/parsing/parse_tab.c \
		srcs/parsing/check_space.c \
		srcs/parsing/get_colors.c \
		srcs/parsing/parsing_map.c \
		srcs/parsing/check_two.c \
		srcs/parsing/get_the_line.c \
		srcs/parsing/player_pos.c \
		srcs/parsing/check_wall_bis.c \
		srcs/parsing/gnl.c \
		srcs/parsing/print_tab.c \
		srcs/parsing/cpy_map.c \
		srcs/parsing/gnl_suite.c \
		srcs/parsing/rgb_check.c \
		srcs/parsing/create_map.c \
		srcs/parsing/joi.c \
		srcs/parsing/space.c \
		srcs/parsing/create_tab_bis.c \
		srcs/parsing/last_for_screen.c \
		srcs/parsing/taby.c \
		srcs/parsing/create_tab.c \
		srcs/parsing/lens.c \
		srcs/parsing/free_all.c \
		srcs/parsing/load_file_utils.c\
		srcs/fun/load_textures_bonus.c\
		srcs/fun/load_gif.c\
		srcs/load_textures.c\
		srcs/fun/time.c\
		srcs/fun/menu.c\
		srcs/fun/menu_utils.c\
		srcs/setting.c\
		srcs/fun/menu_colors.c\
		srcs/fun/menu_speed.c\
		srcs/fun/exit_menu.c\
		srcs/fun/minimap.c\
		srcs/fun/sea.c\
		srcs/exit.c\
		srcs/fun/menu_setting.c\
		srcs/fun/load_textures_bonus2.c\
		srcs/raycasting/transparency.c\
		srcs/fun/minimap2.c\
		srcs/fun/menu_setting2.c\
		srcs/raycasting/background.c\
		srcs/fun/drago.c

SRCS_MAIN = srcs/main.c

SRCS_MAIN_B = srcs/main_b.c

OS_NAME = $(shell uname -s)
CINCLUDES = -I $(INCLUDES)

OBJS = $(SRCS:.c=.o) $(SRCS_MAIN:.c=.o)

OBJS_B = $(SRCS:.c=.o) $(SRCS_MAIN_B:.c=.o)

MLX_OS = 
ifeq ($(OS_NAME), Linux)
	MLX_IS = $(MLX_LINUX)
	CINCLUDES += -I $(MLX_LINUX)
	MLX_OS += -L $(MLX_LINUX) -lmlx -lXext -lX11 -lm
endif
ifeq ($(OS_NAME), Darwin)
	MLX_IS = $(MLX_MAC)
	CINCLUDES += -I $(MLX_MAC)
	MLX_OS += -L $(MLX_MAC) -lmlx -framework OpenGL -framework Appkit -lm
endif

all: $(NAME)

$(NAME): $(OBJS) $(MLX_IS)libmlx.a
	make -C $(MLX_LINUX)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) $(MLX_OS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

bonus: $(BONUS)

$(BONUS): $(OBJS_B) $(MLX_IS)libmlx.a
	make -C $(MLX_LINUX)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS_B) $(MLX_OS) -o $(BONUS)

$(MLX_IS)libmlx.a:
	make -C $(MLX_IS) all

clean:
	make -C $(MLX_LINUX) clean
	make -C $(MLX_MAC) clean
	rm -rf $(OBJS) $(OBJS_B) 

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
