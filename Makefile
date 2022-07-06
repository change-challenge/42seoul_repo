# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:14:07 by hchang            #+#    #+#              #
#    Updated: 2022/07/06 20:24:44 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#output file names
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

#Libft
DIR_LIBFT = ./libft
LIBFT = libft.a

#ft_printf
DIR_FT_PRINTF = ./ft_printf
FT_PRINTF = libftprintf.a

#Mandatory source
DIR_SRCS_MANDATORY = ./src
FILES_CLIENT = client.c
SRCS_CLIENT = $(addprefix $(DIR_SRCS_MANDATORY)/, $(FILES_CLIENT))
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
FILES_SERVER = server.c
SRCS_SERVER = $(addprefix $(DIR_SRCS_MANDATORY)/, $(FILES_SERVER))
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

#Bonus source
DIR_SRCS_BONUS = ./src
FILES_CLIENT_BONUS = client_bonus.c
SRCS_CLIENT_BONUS = $(addprefix $(DIR_SRCS_BONUS)/, $(FILES_CLIENT_BONUS))
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
FILES_SERVER_BONUS = server_bonus.c
SRCS_SERVER_BONUS = $(addprefix $(DIR_SRCS_BONUS)/, $(FILES_SERVER_BONUS))
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

#Header
HEADER_LIBFT = $(DIR_LIBFT)/libft.h

.PHONY: all clean fclean re bonus

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(HEADER_LIBFT) $(OBJS_CLIENT)
	@echo --------------------------------
	@echo $@ Making...
	make bonus -C $(DIR_FT_PRINTF)
	cp $(DIR_LIBFT)/$(LIBFT) .
	cp $(DIR_FT_PRINTF)/$(FT_PRINTF) .
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -I. -L. -lft -lftprintf -o $(NAME_CLIENT)

$(NAME_SERVER): $(HEADER_LIBFT) $(OBJS_SERVER)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_SERVER) -I. -L. -lft -lftprintf -o $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(HEADER_LIBFT) $(OBJS_CLIENT_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	make bonus -C $(DIR_FT_PRINTF)
	cp $(DIR_LIBFT)/$(LIBFT) .
	cp $(DIR_FT_PRINTF)/$(FT_PRINTF) .
	$(CC) $(CFLAGS) $(SRCS_CLIENT_BONUS) -I. -L. -lft -lftprintf -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(HEADER_LIBFT) $(OBJS_SERVER_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_SERVER_BONUS) -I. -L. -lft -lftprintf -o $(NAME_SERVER_BONUS)

clean:
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_FT_PRINTF)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	$(RM) $(LIBFT) $(FT_PRINTF)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re:
	make fclean
	make all
