/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 08:10:10 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 08:10:11 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int	g_row_find;

int		ft_strcmp(char *s1, char *s2);
t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list *begin_list, void *data);
int		ft_is_in_file(int fd, char *to_find, int size);
void	ft_putstr(char *str);

char	*ft_find_world_file(char *path, char *to_find, int len)
{
	char	char_read;
	char	*world;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 1;
	while (i != len)
	{
		read(fd, &char_read, 1);
		if (char_read == '\n')
			i++;
	}
	read(fd, &char_read, 1);
	while (char_read == ' ' || char_read == ':' || (char_read >= '0' && char_read <= '9'))
		read(fd, &char_read, 1);
	i = 0;
	world = malloc(sizeof(char) * 10);
	while (char_read != '\n')
	{
		world[i] = char_read;
		read(fd, &char_read, 1) ;
		i++;
	}
	close(fd);
	world[i] = 0;
	return (world);
}

int		ft_read_file(char *path, char *to_find, int size, t_list *result)
{
	int fd;
	int ris;

	fd = open(path, O_RDONLY);
	ris = ft_is_in_file(fd, to_find, size);
	close(fd);
	//printf("READ LINE CALL SEARCHING %s: %i (len=%i)[case->%i]\n",to_find, ris,size, size%2);
	if (!ris)
		return (ris);
	//ft_list_push_back(result, ft_find_world_file(path, to_find));
	printf("%s ", ft_find_world_file(path, to_find, ris));
	close(fd);
	return (ris);
}
 