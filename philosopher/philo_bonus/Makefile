# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:09:16 by hchang            #+#    #+#              #
#    Updated: 2022/09/13 19:12:05 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = philo_bonus

CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread

SRCS = philo_bonus.c philo_utils_bonus.c philo_utils2_bonus.c philo_utils3_bonus.c

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
#$(CC) -lpthread $(OBJS) -o $(NAME) -fsanitize=address

lldb: all
	$(CC) $(CFLAGS) -lpthread $(SRCS) -o $(NAME) -g3

re:
	make fclean
	make all

.PHONY: all clean fclean re