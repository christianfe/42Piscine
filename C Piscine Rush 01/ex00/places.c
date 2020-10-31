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
	
	i = 0;
	while (i < 4)
	{
		if (vet[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	value_buco(char *array, int i, int pos)
{
	
}

void	check_colrow(char *data, int *change)
{
	int i;
	char vet[];

	i = 0;
	while (i < 4)
	{
		vet[0] = ris[i];
		vet[1] = ris[i + 4];
		vet[2] = ris[i + 8];
		vet[3] = ris[i + 12];
		if (check_zero(&vet[0]) >= 0)
		{
			vet[check_zero(&vet[0])] = value_buco(data, i, check_zero(&vet[0]));
		}
		i++;
	}
		if (ris [0] == ris [])
}