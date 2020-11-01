/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:31:52 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/01 18:31:56 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_adrr(int space, int i);
int		check_opposite(char *arr, int n, char to_find);
char	get_x(char *data, int i, int x, int type);
int		check_four(char *arr, int start, char to_find);

void	ft_place_6(char *data, char *ris, int i_d, int *change)
{
	if ((i_d == 0 || i_d == 4 || i_d == 12 || i_d == 8) &&
		i_d % 4 == 0 && data[i_d] == '3' && check_opposite(data, i_d, '1') &&
		ris[ft_adrr(0, i_d)] == '2' && ris[ft_adrr(3, i_d)] == '4' &&
		get_x(data, i_d, 2, -1) == '2' && ris[ft_adrr(2, i_d)] == 0 &&
		ris[ft_adrr(1, i_d)] == 0)
	{
		if (ris[ft_adrr(2, i_d)] != '1' && ris[ft_adrr(1, i_d)] != '3')
			*change = 1;
		ris[ft_adrr(2, i_d)] = '1';
		ris[ft_adrr(1, i_d)] = '3';
	}
	if ((i_d == 3 || i_d == 15 || i_d == 11 || i_d == 7) &&
		i_d % 4 == 0 && data[i_d] == '3' && check_opposite(data, i_d, '1') &&
		ris[ft_adrr(0, i_d)] == '2' && ris[ft_adrr(3, i_d)] == '4' &&
		get_x(data, i_d, 2, 1) == '2' && ris[ft_adrr(2, i_d)] == 0 &&
		ris[ft_adrr(1, i_d)] == 0)
	{
		if (ris[ft_adrr(2, i_d)] != '3' && ris[ft_adrr(1, i_d)] != '1')
			*change = 1;
		ris[ft_adrr(2, i_d)] = '3';
		ris[ft_adrr(1, i_d)] = '1';
	}
}

void	ft_place_7(char *data, char *ris, int i_d, int *change)
{
	if (data[i_d] == '3' && check_opposite(data, i_d, '1') &&
	ris[ft_adrr(2, i_d)] == '2' && ris[ft_adrr(3, i_d)] == '4' &&
	ris[ft_adrr(0, i_d)] == 0 && ris[ft_adrr(1, i_d)] == 0)
	{
		if (ris[ft_adrr(0, i_d)] != '1' && ris[ft_adrr(1, i_d)] != '3')
			*change = 1;
		ris[ft_adrr(0, i_d)] = '1';
		ris[ft_adrr(1, i_d)] = '3';
	}
	if (data[i_d] == '3' && check_opposite(data, i_d, '1') &&
	ris[ft_adrr(2, i_d)] == '1' && ris[ft_adrr(3, i_d)] == '4' &&
	ris[ft_adrr(0, i_d)] == 0 && ris[ft_adrr(1, i_d)] == 0)
	{
		if (ris[ft_adrr(0, i_d)] != '2' && ris[ft_adrr(1, i_d)] != '3')
			*change = 1;
		ris[ft_adrr(0, i_d)] = '2';
		ris[ft_adrr(1, i_d)] = '3';
	}
}

void	ft_place_8(char *data, char *ris, int i_d, int *change)
{
	if (data[i_d] == '3' && check_opposite(data, i_d, '1') &&
		ris[ft_adrr(2, i_d)] == '3' && ris[ft_adrr(3, i_d)] == '4' &&
		ris[ft_adrr(0, i_d)] == 0 && ris[ft_adrr(1, i_d)] == 0 &&
		ris[ft_adrr(0, i_d)] == 0)
	{
		if (ris[ft_adrr(0, i_d)] != '2' && ris[ft_adrr(1, i_d)] != '1')
			*change = 1;
		ris[ft_adrr(0, i_d)] = '2';
		ris[ft_adrr(1, i_d)] = '1';
	}
	if ((i_d == 3 || i_d == 15 || i_d == 11 || i_d == 7) &&
	data[i_d] == '3' && check_opposite(data, i_d, '1') &&
	ris[ft_adrr(3, i_d)] == '4' && ris[ft_adrr(0, i_d)] == '2' &&
	get_x(data, i_d, 1, 1) == '3' && ris[ft_adrr(1, i_d)] == 0 &&
	ris[ft_adrr(2, i_d)] == 0)
	{
		if (ris[ft_adrr(1, i_d)] != '1' && ris[ft_adrr(2, i_d)] != '3')
			*change = 1;
		ris[ft_adrr(1, i_d)] = '1';
		ris[ft_adrr(2, i_d)] = '3';
	}
}

void	ft_place_9(char *data, char *ris, int i_d, int *change)
{
	if ((i_d == 0 || i_d == 4 || i_d == 12 || i_d == 8) &&
		data[i_d] == '3' && check_opposite(data, i_d, '1') &&
		ris[ft_adrr(3, i_d)] == '4' && ris[ft_adrr(0, i_d)] == '2' &&
		get_x(data, i_d, 1, -1) == '3' && ris[ft_adrr(1, i_d)] == 0 &&
		ris[ft_adrr(2, i_d)] == 0)
	{
		if (ris[ft_adrr(1, i_d)] != '3' && ris[ft_adrr(2, i_d)] != '1')
			*change = 1;
		ris[ft_adrr(1, i_d)] = '3';
		ris[ft_adrr(2, i_d)] = '1';
	}
}
