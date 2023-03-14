NAME 	= 	game

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

FLAGS 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

$(NAME):	$(OBJ)

LIB = ./lib

all:	$(NAME)
	@make -s -C $(LIB)
	@gcc $(INC) -o $(NAME) $(OBJ) $(FLAGS) -L$(LIB)

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME)

re: fclean
	@make -s re -C $(LIB)
	@make -s

.PHONY:	all clean fclean re
