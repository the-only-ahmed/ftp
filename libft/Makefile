# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 21:27:05 by jyim              #+#    #+#              #
#    Updated: 2014/04/27 17:22:40 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_putendl.c ft_strcpy.c aff_rev_list_str.c lst_ascii.c get_next_line.c\
	ft_strdup.c ft_strlen.c ft_strncpy.c ft_strnew.c \
	ft_strcmp.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_memset.c ft_memcpy.c ft_memccpy.c ft_isdigit.c ft_isascii.c \
	ft_isprint.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_memmove.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memalloc.c \
	ft_strequ.c ft_strnequ.c ft_strclr.c ft_strsub.c ft_strjoin.c \
	ft_memdel.c ft_strdel.c ft_strtrim.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_itoa.c ft_strsplit.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstadd.c aff_list_str.c \
	ft_strsplit_mult.c ft_strinjoin.c ft_strsplit_mult_def.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@make -C printf
	@gcc $(FLAGS) -I printf/includes -c $(SRC)
	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)

clean:
	@make -C printf clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C printf fclean
	@/bin/rm -f $(NAME)

re: fclean all
