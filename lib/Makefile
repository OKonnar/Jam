NAME 	= 	lib

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

FILE =	libmy

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re