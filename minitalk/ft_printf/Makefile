# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 14:33:20 by jaesjeon          #+#    #+#              #
#    Updated: 2022/07/06 10:59:44 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(HEADERDIR)

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = ../libft
MAIN = main.c
TARGET = a.out

AR = ar
ARFLAGS = -rcus

PRINTFCDIR = .
PRINTFODIR = .
PRINTFCDIR_BONUS = ./bonus
PRINTFODIR_BONUS = ./bonus

HEADERDIR = .

PRINTFC = ft_printf.c		\
		  ft_printf_utils.c	\
		  ft_printf_utils2.c\
		  analysis_pct.c	\
		  make_origin_len.c	\
		  make_cspct.c		\
		  make_diu.c		\
		  make_xp.c

PRINTFC_BONUS = ft_printf_bonus.c		\
				ft_printf_utils_bonus.c	\
				ft_printf_utils2_bonus.c\
				analysis_pct_bonus.c	\
				make_origin_len_bonus.c	\
				make_cspct_bonus.c		\
				make_diu_bonus.c		\
				make_xp_bonus.c

_PRINTFOBJS = $(PRINTFC:.c=.o)
_PRINTFOBJS_BONUS = $(PRINTFC_BONUS:.c=.o)
PRINTFOBJS = $(addprefix $(PRINTFODIR)/, $(_PRINTFOBJS))
PRINTFOBJS_BONUS = $(addprefix $(PRINTFODIR_BONUS)/, $(_PRINTFOBJS_BONUS))

PRINTFHEADER = $(HEADERDIR)/ft_printf.h
PRINTFHEADER_BONUS = $(HEADERDIR)/ft_printf_bonus.h

ifdef WITH_BONUS
	PRINTFCDIR = $(PRINTFCDIR_BONUS)
	PRINTFODIR = $(PRINTFODIR_BONUS)
	PRINTFOBJS = $(PRINTFOBJS_BONUS)
	PRINTFHEADER = $(PRINTFHEADER_BONUS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(PRINTFOBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

exe: $(TARGET)

$(TARGET): $(NAME) $(MAIN) $(INCLUDES)
	$(CC) -g $(MAIN) $(PRINTFC) -I./ -L./ -lftprintf

diu: $(DIU_TARGET)

$(DIU_TARGET): $(NAME) $(MAIN) $(INCLUDES)
	$(CC) -g $(MAIN_DIU) $(PRINTFC) -I./ -L./ -lftprintf

$(PRINTFODIR)/%.o: $(PRINTFCDIR)/%.c $(PRINTFHEADER)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(PRINTFOBJS) $(PRINTFOBJS_BONUS)

fclean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(PRINTFOBJS) $(PRINTFOBJS_BONUS)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus:
	@make WITH_BONUS=1 all
