# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 08:43:54 by ael-kadh          #+#    #+#              #
#    Updated: 2014/03/27 12:48:53 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRC		= ft_putchar.c ft_putstr.c ft_putnbr.c ft_itoa.c ft_strdup.c\
			ft_strlen.c ft_printf.c ft_strjoin.c ft_atoi.c ft_uputnbr.c\
			ft_pointer.c ft_uput2long.c ft_point.c ft_isascii.c ft_printf_2.c\
			ft_printf_3.c printf_defines.c
HEAD	= ./includes/
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror

# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $^ -I $(HEAD)
	@echo "Linking" [ $^ ] $(OK)

clean :
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean : clean
	@rm -f $(NAME) ./includes/libft.h.gch
	@echo "Delete" [ $(NAME) ] $(OK)

re : fclean all

.PHONY: all clean fclean re

