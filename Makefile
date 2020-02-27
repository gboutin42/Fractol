# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 10:43:19 by gboutin           #+#    #+#              #
#    Updated: 2020/02/27 14:52:06 by gboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
CC			= gcc
NAME		= fractol
CFLAGS		= -Wall -Wextra -Werror
MLX			= -framework OpenGL -framework AppKit -lmlx -L /usr/local/lib/
LIBFT		= cd libft && make
LIBFTFILES	= libft/libft.a
OBJDIR		= ./obj/
SRCDIR		= ./srcs/
HDRDIR		= ./includes/
STR			= $<
RED			= \033[1;31m
CYAN		= \033[1;36m
GREEN		= \033[1;32m
NO_COLOR	= \033[0m
SRCS		=	burningship.c \
				ft_put_pixel.c \
				hook.c \
				init.c \
				julia.c \
				julia_2.c \
				creation.c \
				creation_2.c \
				main.c \
				mandelbrot.c \
				inverse_mandelbrot.c \
				mouse.c \
				moving.c \
				tricorn.c \
				zoom.c

SRCFILES = $(addprefix $(SRCDIR), $(SRCS))
OBJFILES = $(addprefix $(OBJDIR), $(OBJ))
OBJ = $(SRCS:.c=.o)

all: $(NAME)
	make -C libft all

$(OBJDIR)%.o: $(SRCDIR)%.c $(HDRDIR)$(NAME).h Makefile
	mkdir -p obj/
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDRDIR)
	printf "$(CYAN)Compiling:$(GREEN)%28s  $(RED)DONE$(NO_COLOR)\r" $(STR)

$(NAME): $(OBJFILES)
	$(LIBFT)
	$(CC) -o $@ $(CFLAGS) $(MLX) $^ $(LIBFTFILES)
	printf "$(CYAN)Executable:\t\t\t\t$(GREEN)[Done]$(NO_COLOR)\n"

clean:
	$(RM) -rf $(OBJDIR)
	cd libft && make fclean

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)Deleted:\t\t\t\t$(NAME)$(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re