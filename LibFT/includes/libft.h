/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:14:48 by juasanto          #+#    #+#             */
/*   Updated: 2022/11/08 11:05:08 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

long long int		ft_atoi(const char *str);
void				*ft_calloc(size_t num, size_t size);
int					ft_islower(int chr);
int					ft_isupper(int chr);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_isblank(int chr);
int					ft_isxdigit(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new_l);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_l);
void				ft_lstiter(t_list *lst, void (*f)(void*));
void				*ft_memchr(const void *str, int chr, size_t lng);
int					ft_memcmp(const void *str1, \
						const void *str2, size_t n);
void				ft_msgerror(char *str, int errno);
char				*ft_strchr(const char *str, int chr);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char pchar, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr_fd(char const *str, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_clean(char *s1, char *s2, int clean);
char				*ft_strmapi(char const *s, \
						char (*f)(unsigned int, char));
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *str1, \
						const char *str2, size_t n);
char				*ft_strnstr(const char *str1, \
						const char *str2, size_t len);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *str);
char				*ft_strrchr(const char *src, int chr);
char				*ft_strrev(char *str);
char				*ft_substr(char const *s, \
						unsigned int start, size_t len);
int					ft_tolower(int chr);
int					ft_toupper(int chr);
void				ft_putnbr(int nb);
void				ft_putchar(char pchar);
void				ft_putstring(char *putstring);
char				*ft_strcpy(char *string_dest, const char *string_src);
void				print_header(char *funcion_name, char *test_name);
void				*ft_memset(void *memset_string, int fill_char, \
					unsigned int num_char);
void				*ft_bzero(void *bzero_string, unsigned int num_char);
void				*ft_memcpy(void *string_dest, const void *string_src, \
						size_t string_leng);
void				*ft_memccpy(void *str_ds, const void *str_src, \
						int ser_c, size_t num_c);
void				*ft_memmove(void *str_ds, const void *str_src, \
						size_t num_c);
int					get_next_line(int fd, char **line);
void				ft_free_array(char **str);
void				ft_free(char *str);
int					ft_matrixlen(char **matrix);

#endif
