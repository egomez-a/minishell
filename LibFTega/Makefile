# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 11:39:06 by egomez-a          #+#    #+#              #
#    Updated: 2022/12/01 16:50:48 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Formato basico de MakeFile
#objetivo: dependencias
#		instrucciones.

NAME		= libft.a
SRCS_DIR	= sources/
OBJ_DIR		= obj/
INC_DIR		= includes/

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
		ft_putnbr_fd.c \
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
		ft_strrev.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c 

SOURCES 	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS 		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
LFLAGS		= -I$(INC_DIR)
CFLAGS 		= -Wall -Wextra -Werror
CC 			= gcc
RM 			= rm -rf

NONE		=	'\033[0m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[0;33m'
BLUE		=	'\033[0;34m'
PURPLE		=	'\033[0;35m'

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) -c $(CFLAGS) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
	@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN) "======== COMPILED  ==========" $(NONE)

clean:
	@echo $(YELLOW) "========== CLEAN ==========" $(NONE)
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJS)
	@echo $(GREEN) "=========== DONE ===========" $(NONE)

fclean: clean
		@echo $(PURPLE) "========== FCLEAN ==========" $(NONE)
		$(RM) $(NAME)
		@echo $(GREEN) "=========== DONE ===========" $(NONE)

re: fclean all

normi: 
	@norminette -R CheckForbiddenSourceHeader $(SRC)

normi_h:
	@norminette -R CheckDefine libft.h

.PHONY: all, clean, fclean, re
