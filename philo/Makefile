NAME = philo
INC = inc
ARGS = 5 20 15 2 0

SRC = src/main.c \
		src/perror.c \
		src/setup.c \
		src/philo.c \
		src/init.c \
		src/utils.c	\
		src/action.c

OBJ = obj/*

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