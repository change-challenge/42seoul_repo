# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:10:55 by hchang            #+#    #+#              #
#    Updated: 2022/08/23 21:54:51 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = ./srcs/
SRCDIR_BONUS_DIR = ./srcs_bonus/

SRCS = $(SRC_DIR)direction.c \
		$(SRC_DIR)move_UD.c \
		$(SRC_DIR)enemy.c \
		$(SRC_DIR)print.c \
		$(SRC_DIR)get_next_line.c \
		$(SRC_DIR)so_long.c \
		$(SRC_DIR)get_next_line_utils.c \
		$(SRC_DIR)sprite.c \
		$(SRC_DIR)hk_hook.c \
		$(SRC_DIR)hk_loop_hook.c \
		$(SRC_DIR)start_game.c \
		$(SRC_DIR)utils1.c \
		$(SRC_DIR)img.c \
		$(SRC_DIR)utils2.c \
		$(SRC_DIR)init_and_draw.c \
		$(SRC_DIR)utils3.c \
		$(SRC_DIR)map_check.c \
		$(SRC_DIR)utils4.c \
		$(SRC_DIR)move_RL.c \
		$(SRC_DIR)window.c

SRCS_BONUS = $(SRCDIR_BONUS_DIR)direction_bonus.c \
			$(SRCDIR_BONUS_DIR)move_UD_bonus.c \
			$(SRCDIR_BONUS_DIR)enemy_bonus.c \
			$(SRCDIR_BONUS_DIR)print_bonus.c \
			$(SRCDIR_BONUS_DIR)get_next_line_bonus.c \
			$(SRCDIR_BONUS_DIR)so_long_bonus.c \
			$(SRCDIR_BONUS_DIR)get_next_line_utils_bonus.c \
			$(SRCDIR_BONUS_DIR)sprite_bonus.c \
			$(SRCDIR_BONUS_DIR)hk_hook_bonus.c \
			$(SRCDIR_BONUS_DIR)hk_loop_hook_bonus.c \
			$(SRCDIR_BONUS_DIR)start_game_bonus.c \
			$(SRCDIR_BONUS_DIR)utils1_bonus.c \
			$(SRCDIR_BONUS_DIR)img_bonus.c \
			$(SRCDIR_BONUS_DIR)utils2_bonus.c \
			$(SRCDIR_BONUS_DIR)init_and_draw_bonus.c \
			$(SRCDIR_BONUS_DIR)utils3_bonus.c \
			$(SRCDIR_BONUS_DIR)map_check_bonus.c \
			$(SRCDIR_BONUS_DIR)utils4_bonus.c \
			$(SRCDIR_BONUS_DIR)move_RL_bonus.c \
			$(SRCDIR_BONUS_DIR)window_bonus.c

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
	$(CC) -o $(BONUS) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

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