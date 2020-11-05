/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:49:15 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/30 09:05:49 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	ft_reverse_str(char *str, int size)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i + size];
		str[i + size] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	unsigned int	lenbase;
	unsigned int	nbr_unsigned;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		dest[i++] = '-';
		nbr_unsigned = (unsigned int)(-1 * nbr);
	}
	else
		nbr_unsigned = (unsigned int)nbr;
	lenbase = ft_strlen(base);
	if (nbr_unsigned == 0)
		dest[i++] = *(base);
	while (nbr_unsigned > 0)
	{
		dest[i++] = *(base + (nbr_unsigned % lenbase));
		nbr_unsigned /= lenbase;
	}
	dest[i] = 0;
	if (nbr < 0)
		ft_reverse_str(dest, 1);
	else
		ft_reverse_str(dest, 0);
}
