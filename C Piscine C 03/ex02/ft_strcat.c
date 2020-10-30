/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 08:43:03 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/27 08:43:53 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *destptr;

	destptr = dest;
	while (*destptr)
		destptr++;
	while (*src)
	{
		*destptr = *src;
		src++;
		destptr++;
	}
	*destptr = 0;
	return (dest);
}
