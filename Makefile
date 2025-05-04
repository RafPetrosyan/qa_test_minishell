NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g \
    -I./includes \
    -I./libraries/readline/include \
    -I./libraries/readline/include/readline


SRC_DIR = sources
OBJ_DIR = objects

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS = -L./libraries/readline/lib -lreadline -lncurses

FORCE:

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c FORCE
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
