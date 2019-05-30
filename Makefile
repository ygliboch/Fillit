# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:19:46 by yhliboch          #+#    #+#              #
#    Updated: 2018/12/12 16:21:27 by omaltsev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME := fillit

SRC_DIR := ./src/
OBJ_DIR := ./obj/
LIB_DIR := ./lib/
INK_DIR := ./ink/

SRC := main.c check_tetrimino.c options.c options2.c matrix.c dancing_links.c square.c cover_uncover.c make_matrix.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INK := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

FLAGS := -Wall -Wextra -Werror
LINK_FLAGS := $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INK_DIR) -I $(LIBFT_INK)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

