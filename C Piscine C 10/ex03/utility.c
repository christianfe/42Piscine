/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:58 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 18:37:00 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03.h"

int		is_printable(unsigned char c)
{
	return (' ' <= c && c <= '~');
}

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int		is_flag_c(char *str)
{
	return (str[0] == '-' && str[1] == 'C');
}
