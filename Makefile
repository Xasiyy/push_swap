NAME = push_swap

SRCS =	srcs/push_swap.c \
		srcs/main.c \
		srcs/swap.c \
		srcs/sort_stack.c \
		srcs/parsing.c \
		srcs/push.c \
		srcs/reverse.c \
		srcs/rotate.c \
		srcs/algo.c \
		srcs/cost.c \
		srcs/ft_atol.c \
		srcs/utils.c \
		srcs/sort_three.c \
		srcs/set_target.c \
		srcs/push_back.c \

INCLUDES = -I include
LIBFT_DIR = libs/Libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

OBJ_DIR = bin
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
