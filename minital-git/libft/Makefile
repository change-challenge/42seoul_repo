# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:15:25 by hchang            #+#    #+#              #
#    Updated: 2022/01/20 20:52:15 by hchang           ###   ########.fr        #
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
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \

CFILE_BONUS := ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

CFILE_A_OBJS := $(CFILE_A:.c=.o)
CFILE_BONUS_OBJS := $(CFILE_BONUS:.c=.o)

ifdef WITH_BONUS
	CFILE_OBJS = $(CFILE_BONUS_OBJS)
else
	CFILE_OBJS = $(CFILE_A_OBJS)
endif

%.o : %.c
	$(GCC) $(CFLAGS) -c -o $@ $<

$(NAME): $(CFILE_OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	rm -rf $(CFILE_A_OBJS) $(CFILE_BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all
bonus:
	$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY: all clean fclean re bonus
