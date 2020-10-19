# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 15:42:17 by thgillai          #+#    #+#              #
#    Updated: 2020/10/19 13:51:16 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	= ./src

SRCS	= conv_c.c conv_per.c conv_s.c ft_printf.c utils.c utils2.c conv_id.c \
		conv_u.c conv_p.c conv_x.c utils3.c

OBJS	= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

NAME	= libftprintf.a

CC	= gcc
RM	= rm -f

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary compiled\033[0m"

all: 		${NAME}

clean:
			${RM} ${OBJS} ${BOBJ}
			@echo "${OUT_PREFIX}\033[38;5;46mObjects cleaned\033[0m"

fclean:		clean
			${RM} ${NAME}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary cleaned\033[0m"

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all c