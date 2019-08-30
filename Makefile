# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keverett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 09:15:05 by keverett          #+#    #+#              #
#    Updated: 2019/08/30 09:21:08 by keverett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

HEADER = ft_ls.h

LIBRARY = libft/libft.a

SRC =	main.c \
		ft_readdir.c \
	  	ft_ls_lstnew.c \
		ft_ls_lstadd.c \
	  	ft_readflag.c \
		ft_finderror.c \
		ft_errorcheck.c \
		ft_printlst.c \
		ft_mergesort.c \
		ft_dellst.c \
		ft_arglst.c \
		ft_flagcount.c \
		ft_flagset.c \
		ft_filestats.c \
		ft_timesplit.c \
		ft_findsize.c \
		ft_numsize.c \
		ft_structstat.c \
		ft_sortlist.c \
		ft_regcomp.c \
		ft_findlen.c \
		ft_linkname.c \
		ft_totalsizelst.c \
		ft_attr.c \
		ft_findtotsize.c \
		ft_grps.c \
		ft_users.c \
		ft_size.c \
		ft_colours.c \
		ft_timecmp.c \
		ft_getname.c \
		ft_acl.c \

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	make -C libft/
	gcc $(FLAGS) $(SRC) $(LIBRARY) -o ft_ls

