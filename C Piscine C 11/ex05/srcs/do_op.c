/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:20:32 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/09 10:20:36 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	make_operation(int a, int b, int (*operation)(int, int))
{
	ft_putnbr(operation(a, b));
	ft_putchar('\n');
}

void	do_op(char **argv)
{
	if (*argv[2] == '+')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), ft_add);
	else if (*argv[2] == '-')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), ft_sub);
	else if (*argv[2] == '*')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), ft_mol);
	else if (*argv[2] == '/')
	{
		if (ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), ft_div);
	}
	else if (*argv[2] == '%')
	{
		if (ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), ft_mod);
	}
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	else if (ft_strlen(argv[2]) == 1 && (*argv[2] == '+' || *argv[2] == '-'
		|| *argv[2] == '*' || *argv[2] == '/' || *argv[2] == '%'))
	{
		do_op(argv);
	}
	else
		ft_putstr("0\n");
	return (0);
}
