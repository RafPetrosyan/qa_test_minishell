NAME = minishell
READLINE = readline
CC = cc

LIBS_DIR = libraries
READLINE_LIB_PATH = $(LIBS_DIR)/readline/lib

INC_DIRS = -I./includes -I./$(LIBS_DIR)/$(READLINE)/include
CFLAGS = -Wall -Wextra -Werror -g $(INC_DIRS)

SRCS_DIR = sources/
OBJS_DIR = objects/

SRCS_NAME = \
	a_minishell.c \
	a_ft_split_tokens.c \
	a_quotes.c \
	a_write_tokens.c \
	dollar.c \
	a_libft.c \
	a_builtins.c \
	a_env.c \
	a_export_sort.c \
	a_ft_cd.c \
	a_ft_export.c \
	a_ft_echo.c \
	a_tokens_to_char.c \
	ft_execve.c \
	a_ft_split.c \
	a_env_to_char.c \
	a_ft_itoa.c \
	a_pipe_commands.c \
	in_redir.c \
	a_ft_exit.c \
	a_ft_printf.c \
	here_doc.c \
	a_here_doc_init.c \
	a_memmory_free.c \
	a_anyndhat.c \
	a_redirs.c \
	a_allocated_fd_arrs.c \
	a_open_and_run_forks.c \
	redirections.c

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(READLINE_LIB_PATH) -lncurses -l$(READLINE) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

linux_minishell: $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(READLINE_LIB_PATH) -lncurses -l$(READLINE) -o $(NAME)

config_readline:
	./$(LIBS_DIR)/config_readline readline

clean:
	@$(RM) $(OBJS)

fclean: clean
	rm -rf $(LIBS_DIR)/$(READLINE)
	rm -rf $(OBJS_DIR)
	@$(RM) $(NAME)
	make clean -C $(LIBS_DIR)/readline-8.2 || true

fclean_linux: clean
	rm -rf $(LIBS_DIR)/$(READLINE)
	rm -rf $(OBJS_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean fclean_linux re config_readline
