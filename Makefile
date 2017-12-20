TYPE = release
prefix = build-$(TYPE)
obj = $(prefix)/obj
bin = $(prefix)/$(NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
SOURCES =	main.c\
			ft_join_quote.c\
			utils.c\
			env.c\
			error.c
LIBFT = libft/libft.a

OBJECTS = $(addprefix $(obj)/,$(subst .c,.o,$(SOURCES)))
NAME = 42sh

ifeq ($(TYPE),release)
CFLAGS += -O3
else ifeq ($(TYPE),debug)
CFLAGS += -g
endif

include ft_hash_table/files.mk
include ft_readline/files.mk
include ft_exec/files.mk
include ft_history/files.mk
include ft_lexer/files.mk
include ft_parser/files.mk
include ft_free/files.mk
include ft_preprocessing/files.mk
include ft_globbing/files.mk
include ft_builtin/files.mk
include ft_signals/files.mk

.PHONY: all clean fclean norm

all: $(NAME)

$(NAME): $(bin)
	@ln -f $(bin) $(NAME)

$(bin): $(LIBFT) $(OBJECTS)
	@echo "\033[1;35mCCLD \033[0;35m$@\033[0m"
	@$(CC) -o $@ $^ $(LDFLAGS)

$(LIBFT):
	make -C libft

$(obj)/%.o: %.c
	@echo "\033[1;32mCC \033[0;32m$@\033[0m"
	@mkdir -p $(obj)/$(shell dirname $<)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C libft
	rm -rf build-*/obj

fclean:
	make fclean -C libft
	rm -rf build-debug build-release $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)
