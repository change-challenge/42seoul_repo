# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:44:52 by hchang            #+#    #+#              #
#    Updated: 2022/09/13 17:02:51 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = philo

CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -fsanitize=thread

SRCS = philo.c philo_utils.c  philo_utils2.c philo_utils3.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

debug: all
	$(CC) -lpthread $(OBJS) -o $(NAME)

lldb: all
	$(CC) $(CFLAGS) -lpthread $(SRCS) -o $(NAME) -g3

re:
	make fclean
	make all

.PHONY: all clean fclean re