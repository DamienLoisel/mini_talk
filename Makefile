# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 00:46:48 by dloisel           #+#    #+#              #
#    Updated: 2024/07/02 13:42:28 by dloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

NAME = client
NAME2 = server

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = source/client.c

SRC2 = source/server.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

LIBFT = ./include/libft/libft.a
PRINTF = ./include/ft_printf/libftprintf.a
GNL = ./include/get_next_line/get_next_line.a

all: $(NAME) $(NAME2)


$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)Client compiled."

$(NAME2): $(OBJ2) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJ2) $(LIBFT) $(PRINTF) $(GNL) $(CFLAGS) -o $(NAME2)
	@echo "$(GREEN)Server compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Making libft..."
	@make bonus --no-print-directory -C ./include/libft

$(PRINTF):
	@echo "$(YELLOW)Making printf..."
	@make --no-print-directory -C ./include/ft_printf

$(GNL):
	@echo "$(YELLOW)Making GNL..."
	@make --no-print-directory -C ./include/get_next_line

clean:
	@echo "$(RED)make clean..."
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	@rm -f $(OBJS_BONUS)
	@make clean --no-print-directory -C ./include/libft
	@make clean --no-print-directory -C ./include/ft_printf
	@make clean --no-print-directory -C ./include/get_next_line

fclean: clean
	@echo "$(RED)make fclean..."
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f $(NAME_BONUS)
	@make fclean --no-print-directory -C ./include/libft
	@make fclean --no-print-directory -C ./include/ft_printf
	@make fclean --no-print-directory -C ./include/get_next_line

re: fclean all

bonus: all
	@echo
	@echo "$(GREEN)██████╗  █████╗ ███╗  ██╗██╗   ██╗ ██████╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ██║██║   ██║██╔════╝"
	@echo "$(GREEN)██████╦╝██║  ██║██╔██╗██║██║   ██║╚█████╗ "
	@echo "$(GREEN)██╔══██╗██║  ██║██║╚████║██║   ██║ ╚═══██╗"
	@echo "$(GREEN)██████╦╝╚█████╔╝██║ ╚███║╚██████╔╝██████╔╝"
	@echo "$(GREEN)╚═════╝  ╚════╝ ╚═╝  ╚══╝ ╚═════╝ ╚═════╝ "
	@echo
	@echo "$(GREEN) █████╗  █████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗ ██╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗██║"
	@echo "$(GREEN)██║  ╚═╝██║  ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║██║"
	@echo "$(GREEN)██║  ██╗██║  ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║╚═╝"
	@echo "$(GREEN)╚█████╔╝╚█████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝██╗"
	@echo "$(GREEN) ╚════╝  ╚════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ ╚═╝"
	@echo

.PHONY: all clean fclean re bonus
