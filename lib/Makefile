NAME    =    libmy.a

SRC = $(shell echo ./*.c)

OBJ	  =		$(SRC:.c=.o)

RM    =		rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:    clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re