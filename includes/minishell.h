/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:53:58 by juasanto          #+#    #+#             */
/*   Updated: 2023/03/27 13:39:54 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Libraries
*/
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include "../LibFT/includes/libft.h"

/*
** Defines
*/

# define SPACE 32
# define DQU 34
# define SQU 39
# define PIPE 124
# define LESS 60
# define MORE 62
# define DOLLAR 36
# define DOLARG 361
# define DOLENC 366
# define CMD 300
# define ARG 288
# define HERE 388
# define APPEND 488
# define RD 588

/*
** Funcion como structure
*/
struct		s_main;

typedef struct s_func
{
	int		asci;
	void	(*func)(struct s_main *main);
}			t_func;

/*
** Structures
*/
typedef struct s_token
{
	char	*word;
	char	*extvar;
	int 	type;
	int		fd;
	int		quote;
	int 	listsize;
}				t_token;

typedef struct s_exe
{
	char	*cmd;
	char	**args;
	int 	fd_in;
	int		fd_out;
}				t_exe;

typedef struct s_pip
{
	pid_t		p1;
}				t_pip;

typedef struct s_envel
{
	char	*name;
	char	*value;
}				t_envel;

typedef struct s_main
{
	int			argc;
	char		**argv;
	char		**env;
	char		*line;
	char		*home;
	char		*temp_pwd;
	char		*temp_oldpwd;
	int			lenght_line;
	t_pip		pid;
	t_list		*commands;
	t_token		*tokens;
	t_exe		*exe_commands;
	t_list		*envl;
	t_envel		*envlist;
	int			control;
	int			ret;
	t_func		func[5];
	int			ex;
	int 		listsize;
	int			dollaralone;
}				t_main;


/*
** Main (minishell.c)
*/

int		main(int argc, char **argv, char **env);
void	export_token(t_main *main);
void	check_first_token(t_main *main);
int		fn_exe_cm(t_main *main);

/*
** Init (fn_init.c)
*/

char	*check_prompt(int argc, char **argv);
void	*chk_here1(t_main *main, int cnt);
t_main	*fn_init_main(t_main *main, int argc, char **argv, char **env);
int		fn_clean_quotes(t_main *main);

/*
** List Utilities env (fn_envlist.c)
*/
t_envel	*fn_enve_new(char *envi, char *string);
char	**fn_myenv(void);
void	ft_env_list(t_main *main, char **env);

/*
**	List Unilities lists and matrix (fn_utilist.c)
*/

char	**args_list_into_matrix(t_main *main);
void	print_list(t_list *list);
void	first_token_cmd(t_list *list);

/*
**	Creation of tokens (fn_token.c)
*/

t_token	*fn_token_list(t_main *main);
int		word_nam(t_main *main, int type, int separator, int cnt);
t_token	*fn_token_new(char *word, int type, int fd, int quo);

/*
** Check characters 1 (fn_chk1.c)
*/

int		chk_here(t_main *main, int cnt);
int		chk_redirect(t_main *main, int cnt);
int		chk_pipe(t_main *main, int cnt);
int		chk_quote(t_main *main, int cnt);

/*
** Check characters 2 (fn_chk2.c)
*/

int		chk_dollar_alone(t_main *main, int cnt);
int		chk_dollar(t_main *main, int cnt);
int		chk_all(t_main *main, int cnt);
int		chk_dollar_ext(t_main *main);

/*
** Clear tokens (fn_free.c)
*/

void	ft_free_list(t_list *list);
void	ft_free_envel(void *content);
void	fn_free_exe(t_exe *exe_commands);
void	fn_lstdelone(t_list *commands, void (*del)(void *));
void	ft_tokenclear(t_list **commands, void (*del)(void *));
void 	ft_free_token(void *content);
void	ft_freemain(t_main *main);

/*
** Execute functions (fn_execute.c)
*/
int		check_builtins(t_main *main);
void    fn_check_word(t_list *list, t_main *main);

/*
** Built-in (fn_builtin_cd.c)
*/

char    *update_oldpwd(t_main *main);
void    update_key_envvariables(t_main *main);
void    key_envvariables(t_main *main);
int     ft_cd_alone(t_main *main);
int 	fn_cd(t_main *main);

/*
** Built-in (fn_builtin_echo.c)
*/

// static int	number_of_arguments(char **args);
void		print_echo(char **args, int n_flag);
int			flag_treatment(char **args);
int			flag_n_check(char *args);
char 		**tokens_into_matrix(t_main *main);
int			fn_echo(t_main *main, int n_flag);

/*
** Built-in (fn_builtin_env.c)
*/

void	print_envlist(t_list *list);
char	**paths_with_separator(char *paths);
char	**paths_from_env(t_main *main);
int		fn_env(t_main   *main);

/*
** Built-in (fn_builtin_exit.c)
*/

int		fn_exit(t_main *main);

/*
** Built-in (fn_builtin_export.c)
*/

char    **env_to_matrix(int num, t_list *list);
int     order_env_matrix(char **matrix, int num);
int		fn_export(t_main *main);


/*
** Built-in (fn_builtin_pwd.c)
*/

int		fn_pwd(void);

/*
** Built-in (fn_builtin_unset.c)
*/

int		fn_unset(t_main *main);

#endif
