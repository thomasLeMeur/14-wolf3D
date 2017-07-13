/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:40:48 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/12 18:47:58 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** Utility **
*/
# define GNL_BUFF_SIZE			32
# define MAX_NB_FD				256
# define FT_ABS( x )			( ( (x) < 0 ) ? -(x) : (x) )
# define FT_MIN( a, b )			( ( (a) < (b) ) ? (a) : (b) )
# define FT_MAX( a, b )			( ( (a) < (b) ) ? (b) : (a) )
# define FT_SWAP( a, b, type )	{ type c = (a); (a) = (b); (b) = c; }

/*
** Types **
*/
typedef unsigned char	t_uchar;

enum					e_rb_btree_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_data
{
	void	*data;
	size_t	data_size;
}						t_data;

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct			s_btree
{
	void					*content;
	size_t					content_size;
	enum e_rb_btree_color	color;
	struct s_btree			*left;
	struct s_btree			*right;
	struct s_btree			*parent;
}						t_btree;

typedef struct			s_map
{
	t_data			*key;
	t_data			*value;
	struct s_map	*next;
}						t_map;

typedef struct			s_fract
{
	int				sig;
	unsigned int	top;
	unsigned int	bottom;
}						t_fract;

/*
** Utility **
*/
int						ft_printf(char *fmt, ...);
int						ft_gnl(int const fd, char **line);
int						ft_printf_fd(int fd, char *fmt, ...);
int						ft_sprintf(char **buf, char *fmt, ...);
int						ft_gnlmulti(int const fd, char **line);
unsigned int			ft_pgcd(unsigned int a, unsigned int b);
unsigned int			ft_ppcm(unsigned int a, unsigned int b);

/*
** Fractions **
*/
t_fract					ft_fractsimplify(t_fract a);
t_fract					ft_fractadd(t_fract a, t_fract b);
t_fract					ft_fractsub(t_fract a, t_fract b);
t_fract					ft_fractmul(t_fract a, t_fract b);
t_fract					ft_fractdiv(t_fract a, t_fract b);
t_fract					ft_fractcreate(int top, int bottom);

/*
** Memory **
*/
void					ft_memdel(void **ap);
void					*ft_memalloc(size_t size);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memdup(const void *src, size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memrealloc(void *s, size_t old_n, size_t new_n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_memequ(const void *s1, const void *s2, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);

/*
** String **
*/
char					*ft_itoa(int n);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
char					*ft_strrev(char *str);
int						ft_atoi(const char *s);
char					*ft_strnew(size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
char					*ft_strtrim(char const *s);
char					*ft_itoa_base(int nb, int base);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
void					ft_striter(char *s, void (*f)(char *));
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strcat(char *dest, const char *src);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strequ(char const *s1, char const *s2);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strstr(const char *s, const char *target);
size_t					ft_strlcat(char *dest, const char *src, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strnstr(const char *s, const char *target,
						size_t n);
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);

/*
** Char **
*/
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isnumber(const char *s);

/*
** Output **
*/
void					ft_putnbr(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putbin(void *val, size_t size);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);

/*
** Tab **
*/
void					ft_tabdel(void ***as);
void					ft_tabclr(void *array, size_t size);
void					ft_tabset(void *tab, void *val, size_t tab_size,
						size_t content_size);
void					ft_tabiter(void *tab, size_t tab_size,
						size_t content_size, void (*f)(void *, size_t));
void					*ft_tabmap(void *tab, size_t tab_size,
						size_t content_size, void (*f)(void *, size_t));
void					ft_tabsort(void *tab, size_t tab_size,
						size_t content_size,
						int (*cmp)(const void *, const void *, size_t));

/*
** Data **
*/
void					ft_datadel(t_data **data);
t_data					*ft_datadup(t_data *other);
t_data					*ft_datacpy(t_data *a, t_data *b);
t_data					ft_datatmp(void *data, size_t data_size);
t_data					*ft_datanew(void *data, size_t data_size);
int						ft_datacmp(const t_data *a, const t_data *b);
int						ft_dataequ(const t_data *a, const t_data *b);

/*
** List **
*/
int						ft_lstsize(t_list *lst);
void					ft_lstrev(t_list **alst);
void					ft_lstpop(t_list **alst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstdequeue(t_list **alst);
t_list					*ft_lstfrom_string_tab(char **tab);
t_list					*ft_lstat(t_list *lst, size_t pos);
t_list					*ft_lstsplit(char const *s, char c);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstpush(t_list **alst, t_list *add);
t_list					*ft_lstfrom_btree_infix(t_btree *test);
t_list					*ft_lstfrom_btree_prefix(t_btree *test);
t_list					*ft_lstfrom_btree_suffix(t_btree *test);
void					ft_lstcat(t_list **alst, t_list *other);
void					ft_lstenqueue(t_list **alst, t_list *add);
t_list					*ft_lstfrom_btree_bylevel_up(t_btree *root);
t_list					*ft_lstfrom_btree_bylevel_down(t_btree *root);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list					*ft_lstfrom_mapkeys_byvalue(t_map *map, t_data *value);
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstsort(t_list *lst,
						int (*cmp)(const t_list *, const t_list *));
t_list					*ft_lstfrom_void_tab(const void *tab, size_t tab_size,
						size_t content_size);
void					ft_lstinsert(t_list **alst, t_list *add,
						int (*cmp)(const t_list *, const t_list *));
void					ft_lstmerge(t_list **alst, t_list *other,
						int (*cmp)(const t_list *, const t_list *));
t_list					*ft_lstfind(t_list *lst, const void *content_ref,
						size_t size_ref,
						int (*cmp)(const t_list *, const void *, size_t));

/*
** BTree **
*/
void					ft_btreerev(t_btree *test);
int						ft_btreesize(t_btree *test);
int						ft_btreedepth(t_btree *test);
t_btree					*ft_btreefrom_map(t_map *test);
void					ft_btreedel(t_btree **test, void (*del)(t_data *));
t_btree					*ft_btreenew(const void *test, size_t content_size);
void					ft_btreeiter_infix(t_btree *test,
						void (*f)(void *, size_t));
void					ft_btreeiter_prefix(t_btree *test,
						void (*f)(void *, size_t));
void					ft_btreeiter_suffix(t_btree *test,
						void (*f)(void *, size_t));
t_btree					*ft_btreemap_infix(t_btree *test,
						t_btree *(*f)(const t_data *));
t_btree					*ft_btreemap_prefix(t_btree *test,
						t_btree *(*f)(const t_data *));
t_btree					*ft_btreemap_suffix(t_btree *test,
						t_btree *(*f)(const t_data *));
void					ft_btreedelone(t_btree **root, t_btree **test,
						void (*del)(t_data *));
void					ft_btreeiter_bylevel_up(t_btree *test,
						void (*f)(void *, size_t, int));
void					ft_btreeiter_bylevel_down(t_btree *test,
						void (*f)(void *, size_t, int));
void					ft_btreesort_infix(t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreesort_prefix(t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreesort_suffix(t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreesort_bylevel_up(t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreesort_bylevel_down(t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreeadd(t_btree **root, t_data *test,
						int (*cmp)(const t_btree *, const t_btree *));
void					ft_btreemerge(t_btree **root, t_btree *test,
						int (*cmp)(const t_btree *, const t_btree *));
t_btree					*ft_btreefind_infix(t_btree *test,
						const void *content_ref, size_t size_ref,
						int (*cmp)(const t_btree *, const void *, size_t));
t_btree					*ft_btreefind_prefix(t_btree *test,
						const void *content_ref, size_t size_ref,
						int (*cmp)(const t_btree *, const void *, size_t));
t_btree					*ft_btreefind_suffix(t_btree *test,
						const void *content_ref, size_t size_ref,
						int (*cmp)(const t_btree *, const void *, size_t));
t_btree					*ft_btreefind_bylevel_up(t_btree *test,
						const void *content_ref, size_t size_ref,
						int (*cmp)(const t_btree *, const void *, size_t));
t_btree					*ft_btreefind_bylevel_down(t_btree *test,
						const void *content_ref, size_t size_ref,
						int (*cmp)(const t_btree *, const void *, size_t));

/*
** Map **
*/
int						ft_mapsize(t_map *map);
t_map					*ft_maplast(t_map *map);
void					ft_mapadd(t_map **map, t_map *other);
t_map					*ft_mapnew(t_data *key, t_data *value);
void					ft_mapmerge(t_map **map, t_map *other);
t_map					*ft_mapitem_bykey(t_map *map, t_data *key);
void					ft_mapiter(t_map *map, void (*f)(t_map *));
t_data					*ft_mapvalue_bykey(t_map *map, t_data *key);
t_data					*ft_mapkey_byvalue_last(t_map *map, t_data *value);
t_data					*ft_mapkey_byvalue_first(t_map *map, t_data *value);
t_map					*ft_mapitem_byvalue_last(t_map *map, t_data *value);
void					ft_mapmodify(t_map *map, t_data *key, t_data *value);
t_map					*ft_mapitem_byvalue_first(t_map *map, t_data *value);
t_map					*ft_mapmap(t_map *map,
						t_map *(*f)(const t_map *other));
void					ft_mapdel(t_map **map,
						void (*del)(t_data *, t_data *));
void					ft_mapdelone(t_map **map, t_map	**rem,
						void (*del)(t_data *, t_data *));
void					ft_mapsort_bykey(t_map **map,
						int (*cmp)(const t_data *, const t_data *));
void					ft_mapsort_byvalue(t_map **map,
						int (*cmp)(const t_data *, const t_data *));
void					ft_mapdel_bykey(t_map **map, t_data *key,
						void (*del)(t_data *, t_data *));
void					ft_mapdelall_byvalue(t_map **map, t_data *value,
						void (*del)(t_data *, t_data *));
void					ft_mapdellast_byvalue(t_map **map, t_data *value,
						void (*del)(t_data *, t_data *));
void					ft_mapdelfirst_byvalue(t_map **map, t_data *value,
						void (*del)(t_data *, t_data *));

#endif
