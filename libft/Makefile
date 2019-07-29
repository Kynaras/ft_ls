# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keverett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 10:35:56 by keverett          #+#    #+#              #
#    Updated: 2019/07/10 07:40:15 by keverett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = ft_atoi.c \
	  	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstaddre.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_cut.c \
		ft_join.c \
		ft_numcount.c \
		ft_iswhitespace.c \
		ft_strclen.c \
		ft_strcdup.c \
		ft_chrlen.c \

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
		gcc $(FLAGS) $(SRC)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
	
