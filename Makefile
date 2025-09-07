# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzt <rzt@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 22:37:10 by rzt               #+#    #+#              #
#    Updated: 2025/07/28 17:57:19 by rzt              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf
INCLUDE_DIR = ./include
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft
MLX_DIR		= ./mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext
LDFLAGS		= -lm

SRC_DIR		= ./src

OBJ_DIR		= obj

SRC_FILES	= \
    $(SRC_DIR)/cub3d.c \
	$(SRC_DIR)/inits/game.c \
	$(SRC_DIR)/events/event.c \
	$(SRC_DIR)/frees/free.c \


OBJS        = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking Cub3d..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(LDFLAGS) -o $(NAME)
	@echo "Cub3d compilation completed!"

$(LIBFT):
	@echo "Compiling Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Libft compilation completed!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	@norminette include/*
	@echo "\n"
	@norminette src/*

run:	all
	@./cub3d

.PHONY: all clean fclean re