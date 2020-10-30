/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:15:48 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/28 10:17:21 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	char				*charptr;
	unsigned int		i;

	charptr = str;
	i = 0;
	while (*charptr != 0)
	{
		i++;
		charptr++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int siz)
{
	char			*d;
	char			*s;
	unsigned int	n;
	unsigned int	dlen;

	d = dst;
	s = src;
	n = siz;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
