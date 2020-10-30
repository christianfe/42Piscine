/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:40:01 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/26 09:40:46 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	char_left;
	unsigned int	l_src;
	unsigned int	i;

	i = 0;
	l_src = 0;
	while (*(src + l_src) != '\0')
		l_src++;
	char_left = size;
	if (char_left != 0)
	{
		while (--char_left != 0)
		{
			if ((*dest++ = *src++) == '\0')
				break ;
		}
	}
	if (char_left == 0 && size != 0)
		*dest = '\0';
	return (l_src);
}
