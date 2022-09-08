NAME = philo_bonus
INC = inc
ARGS = 5 15 15 2 0

SRC = src/main.c \
		src/init.c \
		src/utils.c	\
		src/actions.c \
		src/free.c \
		src/thread.c

OBJ = obj/*.o

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $(OBJ)

$(OBJ): $(SRC)
	@gcc -c $(SRC) -I $(INC);mv *.o obj

run: all
	@./$(NAME) $(ARGS)

clean: 
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all