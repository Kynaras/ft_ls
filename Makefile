NAME = ft_ls.a

HEADER = FT_LS.H

SRC = dir.c \
	  ls_lstadd.c \
	  ls_lstnew.c \
	  ft_checkflag.c \
	  ft_lstdel.c \


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
