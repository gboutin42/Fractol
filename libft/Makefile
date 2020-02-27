# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 14:48:24 by gboutin           #+#    #+#              #
#    Updated: 2020/02/27 14:53:13 by gboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
CC = gcc
NAME = libft.a
STR = $<
CFLAGS = -Wextra -Werror -Wall
OBJDIR = obj/
SRCDIR = srcs/
RED =		\033[1;31m
CYAN =		\033[1;36m
GREEN =		\033[1;32m
NO_COLOR =	\033[0m

SRCS =	ft_abs.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_del_cont.c \
		ft_delgrid.c \
		ft_error.c \
		ft_exit.c \
		ft_get_end_line.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_itoa_base_maj.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstrev.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_num_tables.c \
		ft_print_word_tables.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_size_number.c \
		ft_sqrt.c \
		ft_sqrt_value.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoinf.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strsub_gnl.c \
		ft_strtol.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

OBJ = $(SRCS:.c=.o)
OBJFILES = $(addprefix $(OBJDIR),$(OBJ))

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p obj/
	$(CC) $(CFLAGS) -o $@ -c $^
	printf "$(CYAN)Compiling:$(GREEN)%28s  $(RED)DONE$(NO_COLOR)\r" $(STR)

$(NAME): $(OBJFILES)
	ar rc $(NAME) $(OBJFILES)
	ranlib $(NAME)
	printf "\n$(CYAN)Library:\t\t\t\t$(GREEN)[Done]$(NO_COLOR)\n"

clean:
	$(RM) -rf $(OBJDIR)
	printf "$(RED)Deleted:\t\t\t\tall object files$(NO_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)Deleted:\t\t\t\t$(NAME)$(NO_COLOR)\n"

re: fclean all
.PHONY: all clean fclean
