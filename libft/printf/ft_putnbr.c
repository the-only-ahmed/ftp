/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:33:08 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/25 21:42:49 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr(str);
	free(str);
}

int		ft_point(char const *str, int *i, int x, char *c)
{
	int		integer;
	int		j;
	char	*ch;
	char	*format;

	integer = ft_atoi(&str[*i + 2]);
	if (!integer && !x && c[0] == '0')
	{
		*i += 2;
		return (-4);
	}
	ch = ft_itoa(x);
	if (ft_strlen(ch) < (size_t)integer)
	{
		j = ft_strlen(ch);
		while (j < integer)
		{
			ch = ft_strjoin(c, ch);
			j++;
		}
	}
	format = ft_itoa(integer);
	*i += 1 + ft_strlen(format);
	return (ft_strlen(ch) - ft_strlen(format) - 3);
}

int		ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
