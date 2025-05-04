NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(CURDIR)/readline-install/include
LDFLAGS = -L$(CURDIR)/readline-install/lib
LDLIBS = -lreadline -lncurses

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
