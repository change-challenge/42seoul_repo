NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = $(LIBFT_SRCS_DIR)libft.a

RM = rm -f

AR = ar
ARFLAGS = crs

MAIN_SRCS_DIR = ./srcs
BONUS_SRCS_DIR = ./checker
GNL_SRCS_DIR = ./get_next_line
LIBFT_SRCS_DIR = ./libft

SRCS = $(MAIN_SRCS_DIR)push_swap.c \
	   $(MAIN_SRCS_DIR)command_1.c \
	   $(MAIN_SRCS_DIR)command_2.c \
	   $(MAIN_SRCS_DIR)command_3.c \
	   $(MAIN_SRCS_DIR)operation.c \
	   $(MAIN_SRCS_DIR)parsing_1.c \
	   $(MAIN_SRCS_DIR)parsing_2.c \
	   $(MAIN_SRCS_DIR)sort.c \
	   $(MAIN_SRCS_DIR)sort_mani.c \
	   $(MAIN_SRCS_DIR)sort_utils.c \
	   $(MAIN_SRCS_DIR)indexing.c

BONUS_SRCS = $(BONUS_SRCS_DIR)checker.c \
			 $(BONUS_SRCS_DIR)command_1.c \
			 $(BONUS_SRCS_DIR)command_2.c \
			 $(BONUS_SRCS_DIR)command_3.c \
			 $(BONUS_SRCS_DIR)parsing_1.c \
			 $(BONUS_SRCS_DIR)parsing_2.c \
			 $(BONUS_SRCS_DIR)indexing.c \
			 $(BONUS_SRCS_DIR)operation.c

GNL_SRCS = $(GNL_SRCS_DIR)get_next_line.c \
		   $(GNL_SRCS_DIR)get_next_line_utils.c

libft.a :
	make -C ./libft
	cp ./libft/libft.a ./

all : $(NAME)

bonus : $(BONUS_NAME)

clean :

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

$(NAME) : $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@
	mv $(MAIN_SRCS_DIR)push_swap ./

$(BONUS_NAME) : $(GNL_SRCS) $(LIBFT) $(BONUS_SRCS)
	$(CC) $(CFLAGS) $^ -o $@
	mv $(BONUS_SRCS_DIR)checekr ./

.PHONY : all clean fclean re
