/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 08:48:08 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 08:48:09 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define DEF_DICT "dict/numbers.dict"

typedef	struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

extern t_list		*g_to_free;
extern t_list		*g_result;
extern int			g_first;

int					ft_strlen(char *str);
int					ft_find_nbr(char *nbr, char *path, int lenght);
t_list				*ft_create_elem(void *data);
void				ft_list_push_back(t_list *begin_list, void *data);
int					ft_print_list(t_list *list, int i);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					ft_read_file(char *path, char *to_find, int size);
void				ft_setzero(char *dest, char *nbr, int n, int type);
void				ft_isolate_nbr(char *dest, char *nbr, int n);
char				*ft_rev_cut(char *nbr, int t);
char				*ft_cut(char *nbr, int t);
char				*ft_strcpy(char *dest, char *src);
char				*ft_adv_cut(char *nbr, int min, int max);
int					ft_strcmp(char *s1, char *s2);
int					ft_is_in_file(int fd, char *to_find, int size);
void				ft_list_clear(t_list *begin_list);
int					ft_check_all(char *str);
int					ft_dict_max(char *path);

#endif
