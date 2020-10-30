/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:25:50 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/29 08:27:57 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char *charptr;

	charptr = str;
	while (*charptr != 0)
	{
		write(1, charptr, 1);
		charptr++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_array(char *arr[], int size)
{
	int		i;
	int		k;
	char	*temp;

	i = 1;
	while (i < size)
	{
		k = i;
		while (k < size)
		{
			if (ft_strcmp(arr[k], arr[i]) < 0)
			{
				temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
			k++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	ft_sort_array(argv, argc);
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
