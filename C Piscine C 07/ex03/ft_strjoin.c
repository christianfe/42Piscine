/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:11:07 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/30 09:06:50 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	char	*charptr;
	int		iterator;

	charptr = str;
	iterator = 0;
	while (*charptr != 0)
	{
		iterator++;
		charptr++;
	}
	return (iterator);
}

void	ft_add_sep(char **concatptr, char *sep)
{
	while (*sep)
	{
		**concatptr = *sep;
		sep++;
		*concatptr += 1;
	}
}

void	ft_concatenate(int size, char *concatptr, char **strs, char *sep)
{
	int k;
	int i;

	k = 0;
	while (k < size)
	{
		i = 0;
		while (strs[k][i])
		{
			*concatptr = strs[k][i];
			concatptr++;
			i++;
		}
		if (k == size - 1)
			*concatptr = 0;
		else if (*sep)
			ft_add_sep(&concatptr, sep);
		k++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;
	char	*concatptr;
	int		nbchar;

	if (size)
	{
		nbchar = (strs[size - 1] - *strs) + ft_strlen(strs[size - 1]) + 1;
		concat = (char *)malloc(nbchar + ((ft_strlen(sep) - 1) * (size - 1)));
	}
	else
	{
		concat = malloc(1);
		*concat = 0;
		return (concat);
	}
	concatptr = concat;
	ft_concatenate(size, concatptr, strs, sep);
	return (concat);
}
