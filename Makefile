.PHONY: clean all re fclean
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = so_long.c checkex.c
LIB_PATH = ./libft/libft.a
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)
	@echo "done"

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB_PATH)


clean:
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "$(NAME) deleted"

re: fclean all