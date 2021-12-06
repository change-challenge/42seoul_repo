# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:15:25 by hchang            #+#    #+#              #
#    Updated: 2021/12/05 22:02:43 by hojinjang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

AR := ar
ARFLAGS := -rc
GCC := gcc
CFLAGS := -Wall -Wextra -Werror

CFILE_A := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \

CFILE_A_OBJS := $(CFILE_A:.c=.o)

%.o : %.c
	$(GCC) $(CFLAGS) -c -o $@ $<

$(NAME): $(CFILE_A_OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	rm -rf $(CFILE_A_OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re

