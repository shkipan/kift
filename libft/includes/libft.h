/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:03:47 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/20 19:32:38 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

/*
** MACROS
*/

# define ABS(NUM)	(((NUM) > 0) ? (NUM) : (-NUM))
# define MIN(a, b)	(((a) < (b)) ? (a): (b))
# define MAX(a, b)	(((a) > (b)) ? (a) : (b))
# define BITS_PER_ARRAY	(sizeof(t_bitarray) * 8)
# define ARR_OFFSET(b)	((b) / BITS_PER_ARRAY)
# define BIT_OFFSET(b)	((b) % BITS_PER_ARRAY)

/*
** BASE FUNCTIONS
*/

void				*ft_memset(void *b, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strncat(char *str1, const char *str2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
	size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** SECOND PART FUNCTIONS
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** BONUS FUNCTIONS
*/

typedef uint32_t	t_bitarray;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ADDITIONAL FUNCTIONS
*/
int					ft_isspace(int c);
void				ft_strrev(char *a);
int					ft_digilen(intmax_t n);
int					ft_udigilen(uintmax_t n);
int					ft_wordcount(char *s);
char				*ft_uitoa(uintmax_t n);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wcslen(wchar_t *str);
int					ft_putwcstr(wchar_t *str);
int					ft_putwchar(wchar_t c);
void				ft_strprepend(char **base, char *src);
void				ft_strappend(char **base, char *src);
void				ft_set_bit(t_bitarray *arr, int n);
void				ft_clear_bit(t_bitarray *arr, int n);
int					ft_get_bit(const t_bitarray *arr, int n);
void				ft_clear_bitarray(t_bitarray *arr);
void				ft_print_bitarray(t_bitarray *arr);
void				ft_wstrdel(wchar_t **as);
wchar_t				*ft_wstrdup(const wchar_t *str);
int					get_next_int(char **src);
char				*get_next_word(char **src);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
long long int		ft_llatoi(const char *str);
#endif
