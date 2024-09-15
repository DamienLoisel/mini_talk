# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 16:30:07 by dloisel           #+#    #+#              #
#    Updated: 2024/06/24 16:15:35 by dloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c \
      print_char.c \
      print_digit.c \
      print_pointer.c \
      print_str.c
OBJS = ft_printf.o \
       print_char.o \
       print_digit.o \
       print_pointer.o \
       print_str.o

all : $(NAME)

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
