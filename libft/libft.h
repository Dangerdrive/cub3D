/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2024/11/01 18:20:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isblank(char c);
int					ft_isprint(int c);
char				*ft_itoa(int num);
char				*ft_itoa_base(long long num, int base);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memdel(void *ptr);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
int					ft_numlen(int num);
int					ft_numlen_base(long long num, int base);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putstr(char *str);
char				**ft_split(char *str, char c);
void				*ft_free_split(char **split, size_t len);
char				**ft_strarrcat(char **tab2, char **tab1);
void				ft_strarr_free(char **array, int len);
int					ft_strarr_len(char **tab);
char				**ft_strarr_ndup(char **array, int n);
char				**ft_strarr_dup(char **array);
char				**ft_strarr_sort(char **strarr);
void				ft_strarr_str_replace(char **strarr, char *target,
						char *replcmt);
int					ft_strarr_str(char **strarr, const char *str);
void				ft_strarr_stradd(char ***strarr, const char *str);
char				**ft_strarr_strrm(char **strarr, const char *str);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_i(const char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
void				ft_string_toupper(char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *src, size_t n);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_uitoa_base(unsigned long num,
						int base, const char format);
int					ft_unumlen_base(unsigned long num, int base);
char				*get_next_line(int fd);

#endif
