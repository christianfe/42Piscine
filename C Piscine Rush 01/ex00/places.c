/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:20:39 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 19:20:44 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_adrr(int space, int i);

int		check_zero(char *vet)
{
	int i;
	int ris;

	i = 0;
	ris = -1;
	while (i < 4)
	{
		if (*(vet + i) == 0)
		{
			if (ris == -1)
				ris = i;
			else
				ris = -2;
		}
		i++;
	}
	return (ris);
}

char	return_valur_buco(char *vet)
{
	if (vet[0] == 0)
		return ('1');
	else if (vet[1] == 0)
		return ('2');
	else if (vet[2] == 0)
		return ('3');
	else if (vet[3] == 0)
		return ('4');
	else
		return (0);
}

char	value_buco(char *ris, int i)
{
	char	vet[4];
	int		k;
	char	val_ris;

	vet[0] = 0;
	vet[1] = 0;
	vet[2] = 0;
	vet[3] = 0;
	k = 0;
	while (k < 4)
	{
		if (i <= 3 && i >= 0)
			val_ris = ris[i + (4 * k)];
		else
			val_ris = ris[ft_adrr(k, i)];
		if (val_ris != 0)
			vet[val_ris - '1'] = '1';
		k++;
	}
	return (return_valur_buco(&vet[0]));
}

void	ft_check_colrow_2(char *data, int i)
{
	char	vet[4];
	int		numzero;

	while (i <= 11 && i >= 8)
	{
		vet[0] = data[(i - 8) * 4];
		vet[1] = data[((i - 8) * 4) + 1];
		vet[2] = data[((i - 8) * 4) + 2];
		vet[3] = data[((i - 8) * 4) + 3];
		numzero = check_zero(&vet[0]);
		if (numzero >= 0)
		{
			if (data[ft_adrr(numzero, i)] == 0)
				data[ft_adrr(numzero, i)] = value_buco(data, i);
		}
		i++;
		vet[0] = 0;
		vet[1] = 0;
		vet[2] = 0;
		vet[3] = 0;
	}
}

int		ft_check_colrow(char *data, int i)
{
	char	vet[4];
	int		numzero;

	i = 0;
	while (i <= 3 && i >= 0)
	{
		vet[0] = data[i];
		vet[1] = data[i + 4];
		vet[2] = data[i + 8];
		vet[3] = data[i + 12];
		numzero = check_zero(&vet[0]);
		if (numzero >= 0)
		{
			if (data[ft_adrr(numzero, i)] == 0)
				data[i + (4 * numzero)] = value_buco(data, i);
		}
		i++;
		vet[0] = 0;
		vet[1] = 0;
		vet[2] = 0;
		vet[3] = 0;
	}
	i = 8;
	ft_check_colrow_2(data, i);
	return (1);
}
