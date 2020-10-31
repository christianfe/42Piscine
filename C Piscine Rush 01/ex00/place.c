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

int	check_data(char *data);

void	ft_add_arr(int x, int y, char c);

int		ft_place_data(char *data, char *ris)
{
	int i_d;
	int i_r;

	i_d = 0;
	i_r = 0;
	if (!check_data(data))
		return (0);
	while (i_d < 16)
	{
		if (data[i_d] == 1)
			ft_add_arr(x, y, '');
			ris[get_addr(i_d)];
		i_d++;
	}
	return (1);
}

int	get_addr(int i)
{
	int ris;

	ris = 0;
	if (i <= 3 && i >= 0)
		ris = i;
	else if (i <= 7 && i >= 4)
		ris = i;


	else if (i <= 11 && i >= 8)
		ris = i;
	else if (i <= 15 && i >= 12)
		ris = i;
}