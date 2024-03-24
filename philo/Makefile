# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:40:31 by cmasnaou          #+#    #+#              #
#    Updated: 2024/02/01 12:22:19 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	=	philo
# CC		=	cc
# FLAGS	=	-Wall -Wextra -Werror -pthread
# RM		=	rm -f
# HEADM	=	philo.h
# SRCM	=	philo.c parse.c utils.c\
# 			split.c libft.c 
# OBJM	=	$(SRCM:.c=.o)

# MAGENTA	=	\033[0;35m
# CYAN	=	\033[1;92m
# YELLOW	=	\033[1;33m
# NC		=	\033[0m

# all:	$(NAME)
# $(NAME):$(OBJM)
# 		@$(CC) $(FLAGS) $(OBJM) -o $(NAME)
# 		@echo "🌸 ${CYAN}Done! 🌸 ${NC}use ${MAGENTA}./philo 5 800 200 200 7🌸"
# %.o:%.c	$(HEADM) Makefile
# 		@$(CC) $(FLAGS) -c $< -o $@
# clean:
# 		@$(RM) $(OBJM)
# 		@echo "🌸 ${YELLOW}Cleanup done! 🌸"
# fclean: clean
# 		@$(RM) $(NAME)
# re:		fclean all
# .PHONY:	clean
# # .SILENT: all



NAME	=	philo
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror -pthread
RM		=	rm -f
HEADM	=	philo.h
SRCM	=	philo.c parse.c utils.c\
			split.c libft.c 
OBJM	=	$(SRCM:.c=.o)

MAGENTA	=	\033[0;35m
CYAN	=	\033[1;92m
YELLOW	=	\033[1;33m
NC		=	\033[0m

all:	$(NAME)
$(NAME):$(OBJM)
		$(CC) $(FLAGS) $(OBJM) -o $(NAME)
		echo "🌸 ${CYAN}Done! 🌸 ${NC}use ${MAGENTA}./philo 5 800 200 200 7🌸"
%.o:%.c	$(HEADM) Makefile
		$(CC) $(FLAGS) -c $< -o $@
clean:
		$(RM) $(OBJM)
		echo "🌸 ${YELLOW}Cleanup done! 🌸"
fclean: clean
		$(RM) $(NAME)
re:		fclean all
.SILENT:
.PHONY:	clean