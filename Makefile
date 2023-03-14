NAME 	= 	game

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

FLAGS 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:	$(NAME)
		@gcc $(INC) -o $(NAME) $(OBJ) $(FLAGS)

clean:
	@rm -f $(OBJ)

$(NAME):	$(OBJ)

fclean: clean
	@rm -f $(NAME)

.PHONY:	all clean fclean re
