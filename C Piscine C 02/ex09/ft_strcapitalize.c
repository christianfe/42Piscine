/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:14:10 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/26 13:38:16 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int new;

	i = 0;
	new = 1;
	while (str[i] != 0)
	{
		if (new == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			new = 0;
		}
		else if (new == 1 && str[i] >= 'A' && str[i] <= 'Z')
			new = 0;
		else if (new == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (!((str[i] <= 'z' && str[i] >= 'a')
					|| (str[i] <= 'Z' && str[i] >= 'A')
					|| (str[i] <= '9' && str[i] >= '0')))
			new = 1;
		else
			new = 0;
		i++;
	}
	return (str);
}
