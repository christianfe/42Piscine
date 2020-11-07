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

#include "../includes/ft_rush02.h"
#include <stdio.h>

int		ft_strlen(char *str);
char	*g_nbr;
char	*g_dict;
t_list	*g_result;

int	ft_find_nbr(char *nbr, char *path, t_list *result, int lenght);
t_list	*ft_create_elem(void *data);

int	main(int argc, char **argv)
{
	g_dict = malloc(100 * sizeof(char));
	g_nbr = malloc(100 * sizeof(char));
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
	if (argc == 2 || argc == 3)
	{
		printf("\n\nresult: %i\n\n", ft_find_nbr(g_nbr, g_dict, g_result, ft_strlen(g_nbr)));
	}	
	/*while (g_result->next)
	{
		printf("%s", g_result->data);
		g_result = g_result->next;
	}*/
	
	return (0);
}
 //**CONTROLLO SU INPUT, solo numeri
 //libreria non valida
 //controllo lib