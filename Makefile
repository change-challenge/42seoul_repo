# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:15:25 by hchang            #+#    #+#              #
#    Updated: 2021/11/29 17:23:48 by hchang           ###   ########.fr        #
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

