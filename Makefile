# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 20:31:50 by hchang            #+#    #+#              #
#    Updated: 2022/07/27 21:07:05 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
	   command_1.c \
	   command_2.c \
	   command_3.c \
	   parsing_1.c \
	   parsing_2.c \
	   indexing.c \
	   operation.c \
	   sort.c \
	   sort_many.c \
	   sort_utils.c

SRCS_BONUS = checker.c \
			 command_1_bonus.c \
			 command_2_bonus.c \
			 command_3_bonus.c \
			 parsing_1_bonus.c \
			 parsing_2_bonus.c \
			 indexing_bonus.c \
			 operation_bonus.c \
			 get_next_line.c \
			 get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap

BONUS = checker

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -L ./libft -l ft $^ -o $@

$(BONUS) : $(OBJS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) -L ./libft -l ft $^ -o $@

clean :
	make -C ./libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C ./libft fclean
	$(RM) $(OBJS) $(NAME) $(OBJS_BONUS) $(BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re
