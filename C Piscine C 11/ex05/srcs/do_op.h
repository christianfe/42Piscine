/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:20:21 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/09 10:20:23 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mol(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

#endif
