/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:21:22 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 11:21:29 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_four(char *arr, int start, char to_find)
{
    int i;
    int find;

    start *= 4;
    i = 0;
    find = 0;
    while(i < 4)
    {
        if (*(arr + i + start) == to_find)
            find++;
        i++;
    }
    return (find);
}

int check_opposite(char *arr, int n, char to_find)
{
    int i;

    if (n >= 8)
        n -= 8;
    else
        n += 8;
    if (arr[n] == to_find)
        return(1);
    else
        return (0);
}

int check_data(char *data, char *ris)
{
    int i_d;
    int i_r;

    i_d = 0;
    i_r = 0;
    while (i_d < 16)
    {
        if (i_d % 4 == 0)
            {
                if (check_four(data, i_d, '1') != 1)
                    return (0);
                if (check_four(data, i_d, '4') > 1 )
                    return (0);
            }
            if (check_opposite(data, i_d, '1'))
                return (0);
            if (check_opposite(data, i_d, '4'))
                return (0);
            if (check_opposite(data, i_d, '3'))
                return (0);
        i_d--;
    }
    return (1);
}