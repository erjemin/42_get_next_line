/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:00:06 by mretha            #+#    #+#             */
/*   Updated: 2019/05/15 19:26:35 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlcat(char *c, const char *v, size_t s);
size_t				ft_strlen(const char *c);
t_list				*ft_lstnew(void const *v, size_t s);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_bzero(void *v, size_t s);
void				ft_memdel(void **c);
void				ft_strdel(char **c);
void				ft_strclr(char *c);
void				ft_striter(char *c, void (*f)(char *cc));
void				ft_striteri(char *c, void (*f)(unsigned int i, char *cc));
void				ft_putchar(char c);
void				ft_putstr(char const *c);
void				ft_putendl(char const *c);
void				ft_putnbr(int i);
void				ft_putchar_fd(char c, int i);
void				ft_putstr_fd(char const *c, int i);
void				ft_putendl_fd(char const *c, int i);
void				ft_putnbr_fd(int i, int ii);
void				ft_lstdelone(t_list **tt, void (*f)(void *v, size_t s));
void				ft_lstdel(t_list **tt, void (*f)(void *v, size_t s));
void				ft_lstadd(t_list **tt, t_list *t);
void				ft_lstiter(t_list *t, void (*f)(t_list *c));
void				*ft_memset(void *v, int i, size_t s);
void				*ft_memcpy(void *v, const void *vv, size_t s);
void				*ft_memccpy(void *v, const void *vv, int i, size_t s);
void				*ft_memmove(void *v, const void *vv, size_t s);
void				*ft_memchr(const void *v, int i, size_t s);
void				*ft_memalloc(size_t s);
char				*ft_strdup(const char *c);
char				*ft_strcpy(char *c, const char *cc);
char				*ft_strncpy(char *c, const char *cc, size_t ccc);
char				*ft_strcat(char *c, const char *cc);
char				*ft_strncat(char *c, const char *v, size_t s);
char				*ft_strchr(const char *c, int v);
char				*ft_strrchr(const char *c, int v);
char				*ft_strstr(const char *c, const char *v);
char				*ft_strnstr(const char *i, const char *c, size_t s);
char				*ft_strnew(size_t s);
char				*ft_strmap(char const *c, char (*f)(char cc));
char				*ft_strmapi(char const *c, char (*f)(unsigned int, char));
char				*ft_strsub(char const *c, unsigned int u, size_t s);
char				*ft_strjoin(char const *c, char const *cc);
char				*ft_strtrim(char const *c);
char				*ft_itoa(int i);
char				**ft_strsplit(char const *c, char cc);
int					ft_memcmp(const void *v, const void *vv, size_t s);
int					ft_strcmp(const char *s, const char *ss);
int					ft_strncmp(const char *c, const char *cc, size_t s);
int					ft_atoi(const char *x);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int i);
int					ft_strequ(char const *c, char const *cc);
int					ft_strnequ(char const *cc, char const *c, size_t s);
int					ft_isspace(char c);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
void				ft_stradd(char **line, char *s);
void				ft_strextend(char **src, size_t addlen);
void				ft_strmove2left(char *dest, int position, int len);

#endif
