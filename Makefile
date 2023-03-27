# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:46:35 by juasanto          #+#    #+#              #
#    Updated: 2023/03/27 13:55:08 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	minishell
LIBFT 		= 	libft.a
LIB_DIR		=	Libft/
OBJ_DIR		=	obj/
SRCS_DIR	=	sources/
SRCS		=	minishell.c \
				ft_envlist.c \
				fn_free.c \
				fn_init.c \
				fn_utilist.c \
				fn_token.c \
				fn_chk_1.c \
				fn_chk_2.c \
				fn_execute.c \
				fn_builtin_pwd.c \
				fn_builtin_echo.c \
				fn_builtin_env.c \
				fn_builtin_export.c \
				fn_builtin_unset.c \
				fn_builtin_exit.c \
				fn_builtin_cd.c 

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

NOW			=	$(shell date +"%d-%m-%y %H:%M")

RLINE_FLG_42 =/Volumes/sgoinfre/students/egomez-a/homebrew/Cellar/readline/8.1.2/lib
RLINE_INC_42 =/Volumes/sgoinfre/students/egomez-a/homebrew/Cellar/readline/8.1.2/include
RLINE_FLG_E42 =-L/Users/egomez-a/.brew/Cellar/readline/8.1.2/lib
RLINE_INC_E42 =-I/Users/egomez-a/.brew/Cellar/readline/8.1.2/include
RLINE_FLG_J42 =-L/Users/juasanto/.brew/Cellar/readline/8.1.2/lib
RLINE_INC_J42 =-I/Users/juasanto/.brew/Cellar/readline/8.1.2/include
RLINE_FLG = -L/usr/local/opt/readline/lib
RLINE_INC = -I/usr/local/opt/readline/include/

READLINE_LIB_DIR_FLAG := -L$(shell brew --prefix readline)/lib
READLINE_INC_DIR_FLAG := -I$(shell brew --prefix readline)/include

LFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDFLAGS = -lncurses -lreadline $(READLINE_LIB_DIR_FLAG) 
CPPFLAGS = $(READLINE_INC_DIR_FLAG) 
# LDFLAGS = -lncurses -lreadline $(RLINE_FLG_E42) 
# CPPFLAGS = $(RLINE_INC_E42) 
DEBUGGING = -ggdb
OPTIMIZING = -O3
CC = clang 
LINUX-CC = cc
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/bin/norminette

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m



all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
#		echo Create: $(NAME) Object directory
		@mkdir -p $(OBJ_DIR)
		@$(CC) -c $(DEBUGGING) $(CFLAGS) $(LFLAGS) $< -o $@
#		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@ --Este es el qe hay que poner.
#		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@ -pthread

$(NAME): $(OBJS)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		@make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"

		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
##		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) -pthread
		$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $(OBJS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME)
		@echo "=========== DONE ==========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		@make -C $(LIB_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
gitpush: fclean
		@echo "$(RED)========== GIT_PUSH =========="
		git add .
		git commit -m "MiniShell - $(NOW)"
		git push #--set-upstream origin master
		git status
		@echo "$(RED)=========== DONE ===========$(RESET)"
bonus: all
re: fclean all
norm: all
		$(NORM) $(SRC);
