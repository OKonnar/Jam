NAME 	= 	game

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)

FLAGS 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

LIB_CSFML = -L./libmy -lmy

all:	$(NAME)
	@make -s -C ./libmy
	@gcc -g -o $(NAME) $(OBJ) $(LIB_CSFML) $(FLAGS)

clean:
	@rm -f $(OBJ)
	@make clean -s -C ./libmy

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ./libmy

re: fclean all

.PHONY:	all clean fclean re
