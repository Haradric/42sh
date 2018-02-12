
TYPE = release
prefix = build-$(TYPE)
obj = $(prefix)/obj
bin = $(prefix)/$(NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Ilibft
SOURCES =	main.c\
			utils.c\
			env.c\
			error.c\
			ft_join_quote.c
LIBFT = libft/libft.a

OBJECTS = $(addprefix $(obj)/,$(subst .c,.o,$(SOURCES)))
NAME = 42sh

ifeq ($(TYPE),release)
CFLAGS += -O3
else ifeq ($(TYPE),debug)
CFLAGS += -g
endif

include hash_table/files.mk
include builtin/files.mk
include ft_readline/files.mk
include ft_exec/files.mk
include ft_history/files.mk
include ft_lexer/files.mk
include ft_parser/files.mk
include ft_free/files.mk
include ft_preprocessing/files.mk
include ft_globbing/files.mk
include ft_signals/files.mk

.PHONY: all clean fclean norm

all: $(NAME)

$(NAME): $(bin)
	@ln -f $(bin) $(NAME)

$(bin): $(LIBFT) $(OBJECTS)
	@echo "\033[34mcreating $(NAME)\033[39m"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(LIBFT):
	@make -C libft

$(obj)/%.o: %.c
	@mkdir -p $(obj)/$(shell dirname $<)
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	@echo "\033[34mremoving object files\033[39m"
	@rm -rf build-release/obj build-debug/obj

fclean:
	@make fclean -C libft
	@echo "\033[34mremoving $(NAME)\033[39m"
	@rm -rf build-debug build-release $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)
