.PHONY: clean all re fclean
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = so_long.c checkex.c validmap.c validpath.c readmap.c get_next_line.c arrays.c
LIB_PATH = ./libft/libft.a
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)
	@echo "so_long : done"

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB_PATH)


clean:
	@rm -f $(OBJ)
	@echo "so_long : OBJ deleted"
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
	@make fclean -C ./libft

re: fclean all