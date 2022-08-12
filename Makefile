CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	direction.c \
		move_UD.c \
		enemy.c \
		print.c \
		get_next_line.c \
		so_long.c \
		get_next_line_utils.c \
		sprite.c \
		hk_hook.c \
		start_game.c \
		hk_key_hook.c \
		utils1.c \
		img.c \
		utils2.c \
		init_and_draw.c \
		utils3.c \
		map_check.c \
		utils4.c \
		move_RL.c \
		window.c

SRCS_BONUS = direction.c \
			move_UD.c \
			enemy.c \
			print.c \
			get_next_line.c \
			so_long.c \
			get_next_line_utils.c \
			sprite.c \
			hk_hook.c \
			start_game.c \
			hk_key_hook.c \
			utils1.c \
			img.c \
			utils2.c \
			init_and_draw.c \
			utils3.c \
			map_check.c \
			utils4.c \
			move_RL.c \
			window.c

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
		gcc $(CFLAGS) -c $^ -I./ -o $@

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