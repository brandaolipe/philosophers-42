NAME = philo
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

SRCS =	main.c \
		clean.c \
		init_data.c \
		routine.c \
		simulation.c \
		utils.c \
		utils2.c
 
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cc -g $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re