# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 11:39:06 by egomez-a          #+#    #+#              #
#    Updated: 2022/12/20 14:50:28 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Formato basico de MakeFile
#objetivo: dependencias
#		instrucciones.

LIBDIR = src/
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_free_array.c \
		ft_free.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_islower.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_isxdigit.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_matrixdup.c \
		ft_matrixlen.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_msgerror.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putnbr_fc.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstring.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin_clean.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen_num.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

SOURCES = $(addprefix $(LIBDIR), $(SRCS))
OBJS 	= $(SOURCES:.c=.o)
LFLAGS 	= -I includes/
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f

NAME 	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< $(LFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

normi: 
	@norminette -R CheckForbiddenSourceHeader $(addprefix $(LIBDIR), $(SRCS))

normi_h:
	@norminette -R CheckDefine libft.h

.PHONY: all, clean, fclean, re
