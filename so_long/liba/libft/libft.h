/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:26:00 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:41:48 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int i);

int				ft_isalpha(int i);

int				ft_isascii(int i);

int				ft_isdigit(int i);

int				ft_isprint(int i);

char			*ft_itoa(int n);

void			*ft_memcpy(void *dest, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t len);

int				ft_memcmp(const void *s1, const void *s2, size_t len);

void			*ft_memmove(void *dest, const void *src, size_t len);

void			*ft_memset(void *dest, int c, size_t len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *str, int ch);

char			*ft_strdup(char *src);

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

int				ft_strlen(const char *str);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);

char			*ft_strrchr(const char *str, int ch);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int i);

int				ft_toupper(int i);

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

char			*ft_get_new_chars(int fd, char *saved_lines);
char			*ft_get_line(char *saved_line);
char			*ft_save(char *saved_line);
char			*get_next_line(int fd);
#endif
