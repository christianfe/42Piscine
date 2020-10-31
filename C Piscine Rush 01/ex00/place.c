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

int		ft_adrr(int space, int i)
{
	if (i <= 3 && i >= 0)
		return (i + (4 * space));
	else if (i <= 7 && i >= 4)
		return (((i - 4) * 4) +(3 - space));
	else if (i <= 11 && i >= 8)
		return ((11 - i) + (4 * (3 - space)));
	else if (i <= 12 && i >= 15)
		return (((15 - i) * 4 ) + space);
}

void	ft_add(int space, int i, char c)
{

}

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
		if (data[i_d] == '1')
			ft_add(0, i_d, '4');
		if (data[i_d] == '4')
		{
			ft_add(0, i_d, '1');
			ft_add(1, i_d, '2');
			ft_add(2, i_d, '3');
			ft_add(3, i_d, '4');
		}
		i_d++;
	}
	return (1);
}
