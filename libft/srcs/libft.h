/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:04:52 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 09:12:17 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 32
# define CURR current->content

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int nb);
int					ft_error(char *str, int i);
int					ft_exit(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_sqrt(int nb);
int					ft_sqrt_value(int nb);
int					ft_size_number(int nb);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_get_end_line(char *str);
int					get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat (char *dest, const char *src, size_t size);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long nbr, char *base);
char				*ft_itoa_base_maj(int value, int base);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strrev(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinf(char **s1, char **s2, int nb);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*strsub_gnl(char const *s, unsigned int start, size_t len);
void				ft_del_cont(void *content, size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
long				ft_strtol(const char *nptr, int base);
void				ft_print_num_tables(int **tab, int y, int x);
void				ft_print_words_tables(char **tab);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstrev(t_list **begin);
void				ft_delgrid(int size, char ***grid);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
