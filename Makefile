# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 21:28:19 by ael-kadh          #+#    #+#              #
#    Updated: 2014/05/18 06:33:12 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	server
NAME_C			=	client
SRC				=	server.c servbuiltins.c
SRC_C			=	client.c client_norme.c
HEAD			=	ftp.h
OBJ				=	$(SRC:.c=.o)
OBJ_C			=	$(SRC_C:.c=.o)
FLAGS			=	-Wall -Wextra -Werror -g3

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all : $(NAME) $(NAME_C)

$(NAME) : $(OBJ) $(OBJ_C)
	@make -C libft
	@cc $(OBJ) -L libft -lft libft/printf/libftprintf.a -o $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)
	@cc $(OBJ_C) -L libft -lft libft/printf/libftprintf.a -o $(NAME_C)
	@echo "Compiling" [ $(NAME_C) ] $(SUCCESS)

%.o : %.c
	@cc $(FLAGS) -c -I libft/ -I libft/printf/includes $<

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)
	@rm -f $(OBJ_C)
	@echo "Cleaning" [ $(NAME_C) ] "..." $(OK)


fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)
	@rm -f $(NAME_C)
	@echo "Delete" [ $(NAME_C) ] $(OK)

re : fclean all

.PHONY: all clean fclean re
