# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 11:03:41 by abentaye          #+#    #+#              #
#    Updated: 2024/04/11 09:03:41 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS =	./src/main.c \
		./src/init.c \
		./src/utils.c \
		./src/threads.c \
		./src/philo_actions.c \
		
OBJS = $(SRCS:.c=.o)
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(Y)"Compiling $(NAME)..."$(X)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	@echo $(X)"[INFO] "$(G)"Compilation done"

clean:
	@$(RM) $(OBJS)
	@echo $(X)"[INFO] "$(R)"Objects removed"

fclean:
	@$(RM) $(NAME) $(OBJS)
	@echo $(X)"[INFO] "$(B)"Binary removed"

re: fclean all

.PHONY: all clean fclean re

