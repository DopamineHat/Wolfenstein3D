# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 00:16:21 by adeletan          #+#    #+#              #
#    Updated: 2017/03/15 19:05:02 by adeletan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.SUFFIXES: .SHELL

SHELL = /bin/zsh
CC		=	@gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
INCLUDES=	./includes
TIME    =   0
LIBISFINISHED = 1
ARGUMENTS = 
SRCS	=	ft_memset.c					\
			ft_memnset.c				\
			ft_bzero.c					\
			ft_memcpy.c					\
			ft_memccpy.c				\
			ft_memmove.c				\
			ft_memchr.c					\
			ft_memcmp.c					\
			ft_memcpy_bwd.c				\
			ft_strlen.c					\
			ft_strdup.c					\
			ft_strcpy.c					\
			ft_strncpy.c				\
			ft_strcat.c					\
			ft_strncat.c				\
			ft_strlcat.c				\
			ft_strchr.c					\
			ft_strrchr.c				\
			ft_strstr.c					\
			ft_strnstr.c				\
			ft_strcmp.c					\
			ft_strncmp.c				\
			ft_atoi.c					\
			ft_isalpha.c				\
			ft_isdigit.c				\
			ft_isalnum.c				\
			ft_isascii.c				\
			ft_isprint.c				\
			ft_toupper.c				\
			ft_tolower.c				\
			ft_memalloc.c				\
			ft_memdel.c					\
			ft_strnew.c					\
			ft_strdel.c					\
			ft_strclr.c					\
			ft_striter.c				\
			ft_striteri.c				\
			ft_strmap.c					\
			ft_strmapi.c				\
			ft_strequ.c					\
			ft_strnequ.c				\
			ft_strsub.c					\
			ft_strjoin.c				\
			ft_strtrim.c				\
			ft_strsplit.c				\
			ft_itoa.c					\
			ft_putchar.c				\
			ft_putchar_fd.c				\
			ft_putstr.c					\
			ft_putstr_fd.c				\
			ft_putendl.c				\
			ft_putendl_fd.c				\
			ft_putnbr.c					\
			ft_putnbr_fd.c				\
			ft_lstnew.c					\
			ft_lstdelone.c				\
			ft_lstdel.c					\
			ft_lstadd.c					\
			ft_lstiter.c				\
			ft_lstmap.c					\
			ft_lstlen.c					\
			ft_swap.c					\
			ft_swap_ptr.c				\
			ft_putarray.c				\
			ft_putnarray.c				\
			ft_realloc.c				\
			ft_lpause.c					\
			ft_error_r.c				\
			ft_doublefree.c				\
			ft_strsetnew.c				\
			ft_union.c					\
			ft_sort_array.c				\
			ft_doubledup.c				\
			ft_arraypop.c				\
			get_next_line.c

SRCS_OUTPUT = $(shell ls $(SRCS) 2> /dev/null)
SRCS_TEST = $(shell ls *.c | grep -v main.c)
OBJS_OUTPUT	=	$(SRCS_OUTPUT:.c=.o)
OBJS_TEST	=	$(SRCS_TEST:.c=.o)
OBJS	=	$(SRCS:.c=.o)

# COLORS
C_NO	=	"\033[00m"
C_PURPLE	=	"\033[35m"
C_GREEN 	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GREEN)SUCCESS$(C_NO)
OK		=	$(C_PURPLE)OK$(C_NO)
RED		=	$(C_ERROR)ERROR$(C_NO)
DONE	=	$(C_WARN)DONE$(C_NO)

all: $(NAME)

ifeq ($(LIBISFINISHED),0)
	@rm -f $(OBJS)
else

endif

$(NAME): $(OBJS)
	@ar rc $@ $(OBJS_OUTPUT)
	@ranlib $@
	@echo " "$(SUCCESS)

test : $(OBJS_TEST)
	@echo $(C_ERROR)#######TEST MODE#######$(C_NO)
	@ar rc $(NAME) $(OBJS_TEST)
	@ranlib $(NAME)
	@gcc main.c $(NAME)
	@sleep 0.01
	@$(shell ./a.out $(ARGUMENTS))

%.o: %.c
	$(CC) -c -o $@ $< -I $(INCLUDES)

%.o:
	@echo "Compiling" $@ " ...	"$(RED)
	@echo "ERROR	" [ $@ ] "  	" $(C_ERROR)MISSING$(C_NO)
	@echo

message :
	@echo -n "Compiling & indexing" [ $(NAME) ]

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "...	" $(OK)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean message all

.PHONY: all clean fclean re test message
