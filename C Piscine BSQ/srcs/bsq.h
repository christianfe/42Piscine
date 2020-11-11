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
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_map
{
	int		x_size;
	int		y_size;
	int		size;
	char	full;
	char	empty;
	char	obstacle;
	char	*path;
	int		area;
	int		area_len;
	int		area_col;
	int		*table;
}				t_map;

extern char		*g_path;
extern t_map	g_map;
extern int		*g_table;
extern int		g_start_area;
extern int		g_area;
extern int		g_area_len;
extern int		g_area_col;

int		ft_atoi(int size);
int		ft_is_free(int pos, int offset);
int		ft_is_border(int pos, char c);
void	ft_free_array(void);
int 	ft_calculate_area();
void	ft_place_x(int pos, int len, int rows);
int		ft_create_map();
void	ft_print_map(void);
void	ft_fullize_map();


#endif
