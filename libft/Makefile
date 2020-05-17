# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 23:11:28 by ybesbes           #+#    #+#              #
#    Updated: 2020/05/15 16:17:24 by ybesbes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= libft.a

SRCS		= 	ft_isalpha.c	ft_memccpy.c	ft_memset.c		ft_split.c		ft_strlcpy.c	ft_strnstr.c	ft_toupper.c \
				ft_atoi.c		ft_isascii.c	ft_memchr.c		ft_putchar_fd.c	ft_strchr.c		ft_strlen.c		ft_strrchr.c \
				ft_bzero.c		ft_isdigit.c	ft_memcmp.c		ft_putendl_fd.c	ft_strdup.c		ft_strmapi.c	ft_strtrim.c \
				ft_calloc.c		ft_isprint.c	ft_memcpy.c		ft_putnbr_fd.c	ft_strjoin.c	ft_substr.c		ft_isalnum.c \
				ft_itoa.c		ft_memmove.c	ft_putstr_fd.c	ft_strlcat.c	ft_strncmp.c	ft_tolower.c \

INCLUDES	=	libft.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c -I${INCLUDES} $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all: 			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
