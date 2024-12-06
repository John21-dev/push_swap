CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard ./*.c)
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

NAME = push_swap

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
