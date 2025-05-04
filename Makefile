NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./includes -I./libraries/readline/include -fdiagnostics-color=always

SRC_DIR = sources
OBJ_DIR = objects

SRCS = $(wildcard $(SRC_DIR)/*.c)
ABS_SRCS = $(realpath $(SRCS))
OBJS = $(ABS_SRCS:%.c=%.o)

LIBS = -L./libraries/readline/lib -lreadline -lncurses

# Կոմպիլացիոն կանոնը (տեղադրում է .o ֆայլը նույն վայրում)
%.o: %.c
	@echo ">>> compiling: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Գլխավոր թիրախ
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJ_DIR)
	find $(SRC_DIR) -name '*.o' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
