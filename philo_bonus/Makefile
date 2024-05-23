# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:40:31 by cmasnaou          #+#    #+#              #
#    Updated: 2024/05/21 09:16:35 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus
CC		=	cc -g -fsanitize=address
FLAGS	=	-Wall -Wextra -Werror -pthread
RM		=	rm -f
HEADM	=	philo.h
SRCM	=	philo_bonus.c parse_bonus.c utils_bonus.c\
			split_bonus.c libft_bonus.c main_bonus.c\
			action_bonus.c fork_bonus.c print_bonus.c\
			eat_bonus.c 	check_bonus.c
OBJM	=	$(SRCM:.c=.o)

MAGENTA	=	\033[0;35m
CYAN	=	\033[1;92m
YELLOW	=	\033[1;33m
NC		=	\033[0m

all:	$(NAME)
$(NAME):$(OBJM)
		$(CC) $(FLAGS) $(OBJM) -o $(NAME)
		echo "🌸 ${CYAN}Done! 🌸 ${NC}use ${MAGENTA}./philo_bonus 5 800 200 200 7🌸"
%.o:%.c	$(HEADM) Makefile
		$(CC) $(FLAGS) -c $< -o $@
bonus:	all
clean:
		$(RM) $(OBJM)
		echo "🌸 ${YELLOW}Cleanup done! 🌸"
fclean: clean
		$(RM) $(NAME)
re:		fclean all
.SILENT:
.PHONY:	clean