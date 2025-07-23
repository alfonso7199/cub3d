# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzt <rzt@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 22:37:10 by rzt               #+#    #+#              #
#    Updated: 2025/07/04 17:30:55 by rzt              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
INCLUDE_DIR = ./include
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

SRC_DIR		= ./src

OBJ_DIR		= obj

SRC_FILES	= \
    $(SRC_DIR)/cub3d.c \


OBJS        = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking Cub3d..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME) $(LDFLAGS)
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

.PHONY: all clean fclean re