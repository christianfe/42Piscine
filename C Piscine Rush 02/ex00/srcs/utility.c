/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:03:00 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 09:03:01 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	char	*charptr;
	int		i;

	i = 0;
	charptr = str;
	while (*charptr != 0)
	{
		i++;
		charptr++;
	}
	return (i);
}

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_list_push_back(t_list *begin_list, void *data)
{
	t_list *last;
	t_list *t;

	last = ft_create_elem(data);
	if (!begin_list)
	{
		begin_list = last;
		return ;
	}
	t = begin_list;
	while (t->next)
		t = t->next;
	t->next = last;
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_countrow(char *to_find, char *path)
{
	char car;
	char *tmp;
	int cont;
	int fd;
	int i;

	fd = open(path, O_RDONLY);
	i = 0;
	cont = 1;
	if (!(tmp =(char *)malloc(sizeof(char) * 40)))
		return (0);
	while (read(fd, &car, 1))
	{
		if (car == '\n')
			cont++;
		else if (car <= '0' && car >= '9')
			continue;
		while (car >= '0' && car <= '9')
		{
			tmp[i] = car;
			i++;
			read(fd, &car, 1);
		}
		if (ft_strcmp(tmp, to_find) != 0)
			i = 0;
		else
			break;
	}
	close(fd);
	return (cont);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}
