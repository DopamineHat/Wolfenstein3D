/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:10:59 by adeletan          #+#    #+#             */
/*   Updated: 2017/10/06 04:26:20 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line.h"
# define FD_VALUE 2147483647

char			**ft_arraypop(char **tab, size_t index, int free);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
int				ft_atoi(char const *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char			*ft_strmap(char const*s, char (*f) (char));
void			ft_striteri(char *s, void (*f) (unsigned int, char *));
void			ft_striter(char *s, void (*f) (char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
void			ft_memdel(void **ap);
char			*ft_strdup(char const *s);
size_t			ft_strlen(char const *s);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strstr(char const *big, char const *little);
char			*ft_strnstr(char const *big, char const *little, size_t len);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_strncat(char *s1, char const *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memnset(void *b, int c, size_t len, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpy_bwd(void	*dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlcat(char *s1, char const *s2, size_t size);
void			ft_swap(int *a, int *b);
void			ft_swap_ptr(char **a, char **b);
void			ft_putarray(char **array);
void			ft_putnarray(char **array, size_t end);
void			*ft_realloc(void *ptr, size_t size);
void			ft_lpause(void);
void			*ft_error_n(int op, char *str, int ker);
int				ft_error_0(int op, char *str, int ket);
void			ft_doublefree(char ***s, void (*f)(void *));
char			*ft_strsetnew(size_t size, int c);
char			*ft_union(char **argv);
void			ft_sort_array(char *str);
char			**ft_doubledup(char **tab);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void	const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void			ft_lstdel(t_list **alst, void (*del) (void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f) (t_list *alem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstlen(t_list *list);
#endif
