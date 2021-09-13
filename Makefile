# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 12:24:54 by goliano-          #+#    #+#              #
#    Updated: 2021/09/13 14:40:56 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	./srcs/ft_printf.c ./utils/hex_convertion.c ./utils/putunbr.c \
					./utils/ft_putchar_fd.c ./utils/ft_putnbr_fd.c ./utils/ft_strdup.c \
					./utils/ft_strlcpy.c ./utils/ft_strlen.c

OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus

