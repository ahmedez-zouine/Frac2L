# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 20:13:57 by aez-zoui          #+#    #+#              #
#    Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Header search directory
INCLUDES    = -I includes

# System-dependent flags (Linux X11 by default for 42)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    MLX_FLAGS = -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME_S), Darwin)
    MLX_FLAGS = -lmlx -lXext -lX11 -lm
endif

# Directories
SRCS_DIR    = src
OBJS_DIR    = obj

# Source files
SRCS_FILES  = main.c \
              init.c \
              render.c \
              fractals.c \
              events.c \
              math_utils.c \
              atof.c \
              utils.c

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Header dependencies
HEADER      = includes/fractol.h

# ANSI Color Codes
GREEN       = \033[0;32m
BLUE        = \033[0;34m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)✓ $(NAME) successfully built!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@rm -f *.o

fclean: clean
	@echo "$(YELLOW)Cleaning binary $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
