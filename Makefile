NAME 	= 	game

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)

FLAGS 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

LIB_CSFML = -L./lib -lmy

all:	$(NAME)
	@make -s -C ./lib
	@gcc -g -o $(NAME) $(OBJ) $(LIB_CSFML) $(FLAGS)

clean:
	@rm -f $(OBJ)
	@make clean -s -C ./lib

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ./lib

re: fclean all

.PHONY:	all clean fclean re
