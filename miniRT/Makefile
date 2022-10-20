# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/10/18 16:42:01 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	cc
NAME			=	miniRT
RM 				=	rm -rvf
CFLAGS 			=	-Wall -Wextra -Werror
MANDATORY_DIR	=	mandatory
BONUS_DIR		=	bonus
LIBFT_DIR 		=	libft
MLX_DIR 		=	mlx

MANDA_SRCS 	=	$(MANDATORY_DIR)/minirt.c \
				$(MANDATORY_DIR)/cone.c \
				$(MANDATORY_DIR)/cylinder.c \
				$(MANDATORY_DIR)/hit.c \
				$(MANDATORY_DIR)/light.c \
				$(MANDATORY_DIR)/object_init.c \
				$(MANDATORY_DIR)/plane.c \
				$(MANDATORY_DIR)/put.c \
				$(MANDATORY_DIR)/put2.c \
				$(MANDATORY_DIR)/ray.c \
				$(MANDATORY_DIR)/sphere.c \
				$(MANDATORY_DIR)/texture.c \
				$(MANDATORY_DIR)/utils.c \
				$(MANDATORY_DIR)/utils2.c \
				$(MANDATORY_DIR)/utils3.c \
				$(MANDATORY_DIR)/vector.c \
				$(MANDATORY_DIR)/vector2.c \
				$(MANDATORY_DIR)/vector3.c \
				$(MANDATORY_DIR)/scene.c \
				$(MANDATORY_DIR)/info_init.c \
				$(MANDATORY_DIR)/render.c \
				$(MANDATORY_DIR)/anti.c
BONUS_SRCS 	=	$(BONUS_DIR)/minirt_bonus.c \
				$(BONUS_DIR)/cone_bonus.c \
				$(BONUS_DIR)/cylinder_bonus.c \
				$(BONUS_DIR)/hit_bonus.c \
				$(BONUS_DIR)/light_bonus.c \
				$(BONUS_DIR)/object_init_bonus.c \
				$(BONUS_DIR)/plane_bonus.c \
				$(BONUS_DIR)/put_bonus.c \
				$(BONUS_DIR)/put2_bonus.c \
				$(BONUS_DIR)/ray_bonus.c \
				$(BONUS_DIR)/sphere_bonus.c \
				$(BONUS_DIR)/texture_bonus.c \
				$(BONUS_DIR)/utils_bonus.c \
				$(BONUS_DIR)/utils2_bonus.c \
				$(BONUS_DIR)/utils3_bonus.c \
				$(BONUS_DIR)/vector_bonus.c \
				$(BONUS_DIR)/vector2_bonus.c \
				$(BONUS_DIR)/vector3_bonus.c \
				$(BONUS_DIR)/scene_bonus.c \
				$(BONUS_DIR)/info_init_bonus.c \
				$(BONUS_DIR)/render_bonus.c \
				$(BONUS_DIR)/anti_bonus.c

OBJS_MANDA 	=	$(MANDA_SRCS:.c=.o)
OBJS_BONUS	=	$(BONUS_SRCS:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_MANDA)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)/libmlx.dylib ./
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L. -lmlx $(LIBFT_DIR)/libft.a -framework openGL -framework AppKit

%.o : %.c
	@echo [$<] compiling ...
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus:
	make BONUS_FLAG=1 all

clean:
	make clean -C $(LIBFT_DIR)
	@echo ">>>>>>deleted list<<<<<<<"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo ">>>>>>deleted list<<<<<<<"
	make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(RM) libmlx.dylib

re:
	@make fclean
	@make all

run:
	@make all
	@make clean
	./miniRT

.PHONY: all clean fclean re bonus
