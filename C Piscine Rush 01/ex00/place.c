/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:43:52 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 11:43:54 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_data(char *data);
int		check_opposite(char *arr, int n, char to_find);
void	ft_putstr(char *str);
char	get_x(char *data, int i, int x, int type);
int		ft_check_colrow(char *data, int i);
int		ft_check_char_left(char *ris);
int		check_four(char *arr, int start, char to_find);
void	ft_place_1(char *data, char *ris, int i_d, int *change);
void	ft_place_2(char *data, char *ris, int i_d, int *change);
void	ft_place_3(char *data, char *ris, int i_d, int *change);
void	ft_place_4(char *data, char *ris, int i_d, int *change);
void	ft_place_5(char *data, char *ris, int i_d, int *change);
void	ft_place_6(char *data, char *ris, int i_d, int *change);
void	ft_place_7(char *data, char *ris, int i_d, int *change);
void	ft_place_8(char *data, char *ris, int i_d, int *change);
void	ft_place_9(char *data, char *ris, int i_d, int *change);
void	ft_place_10(char *data, char *ris, int i_d, int *change);

int		ft_adrr(int space, int i)
{
	if (i <= 3 && i >= 0)
		return (i + (4 * space));
	else if (i <= 7 && i >= 4)
		return ((i - 4) + (4 * (3 - space)));
	else if (i <= 11 && i >= 8)
		return (((i - 8) * 4) + space);
	else if (i <= 15 && i >= 12)
		return ((i - 12) * 4 + (3 - space));
	else
		return (-1);
}

void	ft_place_data_0(char *data, char *ris, int i_d, int *change)
{
	ft_place_1(data, ris, i_d, change);
	ft_place_2(data, ris, i_d, change);
	ft_place_3(data, ris, i_d, change);
	ft_place_4(data, ris, i_d, change);
	ft_place_5(data, ris, i_d, change);
	ft_place_6(data, ris, i_d, change);
	ft_place_7(data, ris, i_d, change);
	ft_place_8(data, ris, i_d, change);
	ft_place_9(data, ris, i_d, change);
	ft_place_10(data, ris, i_d, change);
}

int		ft_place_data(char *data, char *ris)
{
	int i_d;
	int change;

	i_d = 0;
	change = 0;
	if (!check_data(data))
		return (0);
	while (i_d < 16)
	{
		ft_place_data_0(data, ris, i_d, &change);
		if (!ft_check_colrow(ris, i_d))
			return (0);
		if (!ft_check_char_left(ris))
			return (0);
		if (change == 1)
			i_d = 0;
		else
			i_d++;
		change = 0;
	}
	return (1);
}
