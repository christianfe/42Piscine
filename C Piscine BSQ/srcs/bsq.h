/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:07:09 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 12:07:18 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int		x_size;
	int		y_size;
	int		size;
	char	full;
	char	empty;
	char	obstacle;
	char	*path;
	int		area;
	int		start_area;
	int		area_len;
	int		area_col;
	int		*table;
}				t_data;

void			ft_fullize_map(t_data *t_map);
int				ft_calculate_up(t_data *t_map, int pos, int up, int len);
int				ft_calculate_down(t_data *t_map, int pos, int down, int len);
int				ft_calculate_len(t_data *t_map, int pos, int len);
int				ft_create_map(t_data *t_map);
int				ft_first_row(t_data *t_map, int fd);
int				ft_calculate_area(t_data *t_map);
void			ft_free_array(t_data *t_map);
int				ft_is_free(t_data *t_map, int pos, int offset);
int				ft_is_border(t_data *t_map, int pos, char c);
int				ft_atoi(t_data *t_map, int size);
void			ft_place_x(t_data *t_map, int pos, int len, int rows);
void			ft_print_map(t_data *t_map);
int				ft_bsq(t_data *t_map);
char			**ft_split(char *str, char *charset);

#endif
