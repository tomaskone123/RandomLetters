NAME		:= random_letters
CFLAGS		:= -Wextra -Wall -Werror
LIBFT		:= ./lib/libft

HEADERS		:= -I ./inc -I $(LIBFT)/include
LIBS		:= $(LIBFT)/libft.a
SRCS		:= $(shell find ./src -iname "*.c")
OBJS		:= ${SRCS:.c=.o}


all: libft $(NAME)

norm:
	@norminette src include

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) -g -fsanitize=address $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) -g -fsanitize=address $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re,
