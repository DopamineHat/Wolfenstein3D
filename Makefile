# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 01:11:02 by rpagot            #+#    #+#              #
#    Updated: 2017/10/21 21:44:02 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

LIBFT = libft/libft.a

CFLAGS := -Wall -Wextra -Werror -g3 -Ofast -march=native
LCFLAGS := -L./minilibx_macos -lmlx -framework OpenGL \
		-framework Appkit -g3 -Ofast -march=native



INCLUDES := -I./minilibx_macos -I./includes -I./libft

SRCS := main.c \
		ft_parse.c \
		ft_init.c \
		ft_player_move.c \
		ft_handle_errors.c \
		ft_process.c \
		raycasting.c \
		ft_draw.c \
		ft_hook_keys.c \
		ft_rainclusterfuck.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/
	make -C minilibx_macos/


$(NAME): $(OBJS)
	gcc $(LCFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

%.o : %.c
	gcc $(CFLAGS)  $(INCLUDES) -c -o $@ $<

clean :
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -rf $(OBJSP) $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
