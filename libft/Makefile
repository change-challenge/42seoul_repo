# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 18:14:29 by minsuki2          #+#    #+#              #
#    Updated: 2022/07/06 10:50:05 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ./libft.a
ARFLAGS = rcus
INCLUDES = ./libft.h
INC = -I./

SRCS_FILES = ft_isalpha.c	\
			 ft_isdigit.c	\
			 ft_isalnum.c	\
			 ft_isascii.c	\
			 ft_isprint.c	\
			 ft_strlen.c	\
			 ft_memset.c	\
			 ft_bzero.c		\
			 ft_memcpy.c	\
			 ft_memmove.c	\
			 ft_toupper.c	\
			 ft_tolower.c	\
			 ft_strchr.c	\
			 ft_strrchr.c	\
			 ft_memchr.c	\
			 ft_strlcpy.c	\
			 ft_strlcat.c	\
			 ft_strncmp.c	\
			 ft_memcmp.c	\
			 ft_atoi.c		\
			 ft_strnstr.c	\
			 ft_calloc.c	\
			 ft_strdup.c

SRCS_FILES += ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_substr.c		\
			  ft_strjoin.c		\
			  ft_strtrim.c		\
			  ft_itoa.c			\
			  ft_split.c		\
			  ft_striteri.c		\
			  ft_strmapi.c

BONUS_SRCS_FILES = ft_lstnew.c			\
			 	   ft_lstadd_front.c	\
			 	   ft_lstsize.c			\
			 	   ft_lstlast.c			\
			 	   ft_lstadd_back.c		\
			 	   ft_lstdelone.c		\
			 	   ft_lstclear.c		\
				   ft_lstiter.c			\
			 	   ft_lstmap.c

SRCS = $(SRCS_FILES)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCLUDES)
	$(CC) $(INC) $(CFLAGS) -c $<

clean:
	$(RM) $(SRCS_FILES:.c=.o) $(BONUS_SRCS_FILES:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	@$(MAKE) "SRCS = $(SRCS_FILES) $(BONUS_SRCS_FILES)" all

.PHONY: all clean fclean re bonus
