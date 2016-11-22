# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleroy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 20:33:14 by mleroy            #+#    #+#              #
#    Updated: 2016/11/21 13:56:46 by mleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c\
	 ft_print_usage.c\
	 ft_read_tetra.c\
	 ft_check_all.c\
	 ft_generate_tetra.c\
	 ft_first_grid.c\
	 ft_solve.c\
	 ./Libft/ft_putchar.c\
	 ./Libft/ft_memset.c\
	 ./Libft/ft_bzero.c\
	 ./Libft/ft_memalloc.c\
	 ./Libft/ft_putstr.c\
	 ./Libft/ft_strlen.c\

OUT=  main.o\
	 ft_print_usage.o\
	 ft_read_tetra.o\
	 ft_check_all.o\
	 ft_generate_tetra.o\
	 ft_first_grid.o\
	 ft_solve.o\
	 ft_putchar.o\
	 ft_memset.o\
	 ft_bzero.o\
	 ft_memalloc.o\
	 ft_putstr.o\
	 ft_strlen.o\

HEADER= fillit.h

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C ./Libft fclean && make -C ./libft
	make -C ./libft clean
	gcc -c $(FLAGS) $(SRC)
	gcc $(OUT) -o $(NAME) -I $(HEADER)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re: fclean all
