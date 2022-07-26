# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 08:08:54 by sesim             #+#    #+#              #
#    Updated: 2022/07/26 12:34:03 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = ./srcs/
SRCS_BONUS_DIR = ./bonus_srcs/

SRCS = $(SRCS_DIR)push_swap.c \
	   $(SRCS_DIR)command_1.c \
	   $(SRCS_DIR)command_2.c \
	   $(SRCS_DIR)command_3.c \
	   $(SRCS_DIR)parsing_1.c \
	   $(SRCS_DIR)parsing_2.c \
	   $(SRCS_DIR)indexing.c \
	   $(SRCS_DIR)operater.c \
	   $(SRCS_DIR)sort.c \
	   $(SRCS_DIR)sort_under_5.c \
	   $(SRCS_DIR)sort_utils.c

SRCS_BONUS = $(SRCS_BONUS_DIR)checker.c \
			 $(SRCS_BONUS_DIR)command_1_bonus.c \
			 $(SRCS_BONUS_DIR)command_2_bonus.c \
			 $(SRCS_BONUS_DIR)command_3_bonus.c \
			 $(SRCS_BONUS_DIR)parsing_1_bonus.c \
			 $(SRCS_BONUS_DIR)parsing_2_bonus.c \
			 $(SRCS_BONUS_DIR)indexing_bonus.c \
			 $(SRCS_BONUS_DIR)operater_bonus.c

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
