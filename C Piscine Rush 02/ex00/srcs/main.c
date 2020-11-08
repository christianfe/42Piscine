/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 08:10:04 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 08:10:05 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

t_list	*g_to_free;
t_list	*g_result;
char	*g_nbr;
char	*g_dict;

int		ft_check_input(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print_error_msg(char *file, char *name_prg)
{
	ft_putstr(basename(name_prg));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	ft_free_memory(void)
{
	t_list	*temp;

	temp = g_to_free;
	while (g_to_free)
	{
		free(g_to_free->data);
		g_to_free = g_to_free->next;
	}
	ft_list_clear(g_result);
	ft_list_clear(temp);
}

void	ft_allocate_var(int argc, char **argv)
{
	if (argc == 2)
	{
		g_nbr = argv[1];
		g_dict = DEF_DICT;
	}
	else if (argc == 3)
	{
		g_nbr = argv[2];
		g_dict = argv[1];
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	g_first = 1;
	if (!((g_dict = malloc(200 * sizeof(char))) &&
		(g_nbr = malloc(200 * sizeof(char)))))
		return (0);
	g_to_free = ft_create_elem(g_dict);
	ft_list_push_back(g_to_free, g_nbr);
	ft_allocate_var(argc, argv);
	if ((fd = open(g_dict, O_RDONLY)) == -1)
	{
		ft_print_error_msg(g_dict, argv[0]);
		return (0);
	}
	close(fd);
	if (!(ft_check_input(g_nbr) && ft_check_all(g_dict)))
		return (0);
	g_result = ft_create_elem("");
	if (!ft_find_nbr(g_nbr, g_dict, ft_strlen(g_nbr)))
		ft_putstr("Dict Error\n");
	else if (!(ft_print_list(g_result, 0)))
		ft_putstr("Dict Error\n");
	ft_free_memory();
	return (0);
}
