/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:51:19 by mwane             #+#    #+#             */
/*   Updated: 2019/10/18 11:33:03 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_atoi(char *nbr);
void	ft_bzero(void *s, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t size);
void	*ft_memchr(const void *s, int c, int size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *s, int c, size_t size);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(const char *str);
int		ft_strlcat(char *dest, char *src, unsigned int size);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int n);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strnstr(char *str, char *to_find, unsigned int len);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
