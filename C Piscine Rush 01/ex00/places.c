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

int check_zero(char *vet)
{
	int i;
	int ris;
	
	i = 0;
	ris = -1;
	while (i < 4)
	{
		if (vet[i] == 0 )
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

char	value_buco(char *array, int i, int pos)
{
	int vet[4];
	int k;

	k = 0;
	while (k < 4)
	{
		vet[(array[i + (4 * pos)]) - '1'] = 1;
		k++;
	}
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

void	ft_check_colrow(char *data, int *change)
{
	int i;
	char vet[4];

	i = 0;
	while (i < 4)
	{
		vet[0] = data[i];
		vet[1] = data[i + 4];
		vet[2] = data[i + 8];
		vet[3] = data[i + 12];
		if (check_zero(&vet[0]) >= 0)
		{
			data[i + (4 * check_zero(&vet[0]))] = value_buco(data, i, check_zero(&vet[0]));
			*change = 1;
		}
		i++;
		vet[0] = 0;
		vet[1] = 0;
		vet[2] = 0;
		vet[3] = 0;
	}
	i = 8;
	while (i < 12)
	{
		vet[0] = data[(i - 8) * 4];
		vet[1] = data[((i - 8) * 4) + 1];
		vet[2] = data[((i - 8) * 4) + 2];
		vet[3] = data[((i - 8) * 4) + 3];
		if (check_zero(&vet[0]) >= 0)
		{
			data[i + (4 * check_zero(&vet[0]))] = value_buco(data, i, check_zero(&vet[0]));
			*change = 1;
		}
		i++;
		vet[0] = 0;
		vet[1] = 0;
		vet[2] = 0;
		vet[3] = 0;
	}
}