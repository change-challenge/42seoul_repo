# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:10:55 by hchang            #+#    #+#              #
#    Updated: 2022/08/25 22:37:51 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCDIR = ./srcs/
SRCDIR_BONUS = ./srcs_bonus/

SRCS = $(SRCDIR)so_long.c \
		$(SRCDIR)window.c \
		$(SRCDIR)map_check.c \
		$(SRCDIR)init_and_draw.c \
		$(SRCDIR)hk_hook.c \
		$(SRCDIR)hk_loop_hook.c \
		$(SRCDIR)enemy.c \
		$(SRCDIR)sprite.c \
		$(SRCDIR)move_UD.c \
		$(SRCDIR)move_RL.c \
		$(SRCDIR)get_next_line.c \
		$(SRCDIR)get_next_line_utils.c \
		$(SRCDIR)utils0.c \
		$(SRCDIR)utils1.c \
		$(SRCDIR)utils2.c \
		$(SRCDIR)utils3.c \
		$(SRCDIR)utils4.c

SRCS_BONUS = $(SRCDIR_BONUS)so_long_bonus.c \
		$(SRCDIR_BONUS)window_bonus.c \
		$(SRCDIR_BONUS)map_check_bonus.c \
		$(SRCDIR_BONUS)init_and_draw_bonus.c \
		$(SRCDIR_BONUS)hk_hook_bonus.c \
		$(SRCDIR_BONUS)hk_loop_hook_bonus.c \
		$(SRCDIR_BONUS)enemy_bonus.c \
		$(SRCDIR_BONUS)sprite_bonus.c \
		$(SRCDIR_BONUS)move_UD_bonus.c \
		$(SRCDIR_BONUS)move_RL_bonus.c \
		$(SRCDIR_BONUS)get_next_line_bonus.c \
		$(SRCDIR_BONUS)get_next_line_utils_bonus.c \
		$(SRCDIR_BONUS)utils0_bonus.c \
		$(SRCDIR_BONUS)utils1_bonus.c \
		$(SRCDIR_BONUS)utils2_bonus.c \
		$(SRCDIR_BONUS)utils3_bonus.c \
		$(SRCDIR_BONUS)utils4_bonus.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = so_long

BONUS = so_long_bonus

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	make -C mlx/
	$(CC) -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

$(BONUS) : $(OBJS_BONUS)
	make -C mlx/
	$(CC) -o $(BONUS) $(OBJS_BONUS) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o		:		%.c
		cc $(CFLAGS) -c $^ -I./ -o $@

clean :
	make -C ./mlx clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C ./mlx clean
	$(RM) $(OBJS) $(NAME) $(BONUS) $(OBJS_BONUS) $(BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re