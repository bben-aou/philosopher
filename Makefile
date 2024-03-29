# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 17:26:48 by virsnp00x         #+#    #+#              #
#    Updated: 2022/05/27 14:21:13 by virsnp00x        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror 

LFLAGS = -pthread

src = 	philo.c \
		simulation.c \
		time.c \
		init_philosophers.c \
		activities.c \
		helpers/ft_atoi.c \
		helpers/ft_isdigit.c \
		errors_messages.c   \
		

HDRS = ./philo.h \

OBJ = $(src:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@gcc $(CFLAGS) $(LFLAGS) $^  -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"
	
%.o: %.c $(HDRS)
	@gcc $(CFLAGS) $(LFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all