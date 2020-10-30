/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:40:31 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/29 09:06:30 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		leng;
	int		i;
	char	*ris;

	leng = 0;
	i = 0;
	while (*(src + leng))
		leng++;
	ris = malloc(leng + 1);
	while (i <= leng)
	{
		ris[i] = src[i];
		i++;
	}
	return (ris);
}
