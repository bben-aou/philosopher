# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 17:26:48 by virsnp00x         #+#    #+#              #
#    Updated: 2022/05/27 14:38:19 by virsnp00x        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror 

# LFLAGS = -pthread

src = 	philosophers.c \
		ft_init.c \
		ft_parsing.c \
		ft_actions.c \

HDRS = ./philosophers.h \

OBJ = $(src:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@gcc $(CFLAGS) $^  -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"
	
%.o: %.c $(HDRS)
	@gcc $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all