NAME = push_swap

SRCS = srcs/push_swap.c  srcs/main.c srcs/sort_stack.c

HEADERS = -I ./include/

LIBFT_DIR = libs/Libft

LIBFT_NAME = libft.a

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME) $(LIBFT_DIR)/$(LIBFT_NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(CC) $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re