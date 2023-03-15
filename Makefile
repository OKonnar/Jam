NAME 	= 	game

SRC		=	$(shell find -name "*.c")

OBJ		=	$(SRC:.c=.o)

FLAGS 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:	$(NAME)
	@gcc -s -g -o $(NAME) $(OBJ) $(FLAGS)

$(NAME):	$(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
