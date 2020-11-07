/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 10:12:06 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 10:12:08 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int		ft_strlen(char *str);
int		ft_read_file(char *path, char *to_find, int size, t_list *result);
void	ft_setzero(char *dest, char *nbr, int n, int type);
void	ft_isolate_nbr(char *dest, char *nbr, int n);
char	*ft_rev_cut(char *nbr, int t);
char	*ft_cut(char *nbr, int t);
char	*ft_strcpy(char *dest, char *src);
char	*ft_adv_cut(char *nbr, int min, int max);

int	ft_find_nbr(char *nbr, char *path, t_list *result, int lenght)
{
	char	*temp;
	int 	i;

	i = 0;
	temp = malloc(sizeof(char) * lenght + 1);
	if (ft_read_file(path, nbr, lenght, result) != 0)
		return (0);
	ft_strcpy(temp, nbr);
	if (lenght == 1)
		ft_read_file(path, temp, lenght, result);
	else if (lenght == 2)
	{
		if ((ft_read_file(path, temp, lenght, result)) == 0)
		{
			ft_setzero(temp, nbr, 1, 0);
			ft_read_file(path, temp, lenght, result);
			ft_find_nbr(ft_rev_cut(nbr, 1), path, result, 1);
		}
	}
	else if ((lenght % 3) == 0)
	{
		ft_read_file(path, nbr, 1, result);
		ft_setzero(temp, nbr, 1, 1);
		ft_read_file(path, temp, 3, result);
		ft_find_nbr(ft_rev_cut(nbr, 1), path, result, 2);
		if (lenght > 3)
		{
			ft_setzero(temp, nbr, 1, 1);
			ft_read_file(path, temp, lenght - 2, result);
			ft_find_nbr(ft_rev_cut(nbr, 3), path, result, lenght - 3);
		}
	}
	else if ((lenght % 3) == 1)
	{
		ft_find_nbr(nbr, path, result, 1);
		ft_setzero(temp, nbr, 1, 1);
		ft_read_file(path, temp, lenght, result);
		ft_find_nbr(ft_rev_cut(nbr, 1), path, result, lenght - 1);
	
	}
	else if ((lenght % 3) == 2)
	{
		
		ft_find_nbr(nbr, path, result, 2);
		ft_setzero(temp, ft_rev_cut(nbr, 1), 1, 1);
		ft_read_file(path, temp, lenght-1, result);
		ft_find_nbr(ft_rev_cut(nbr, 2), path, result, lenght - 2);		
	}
	return (1);
}
