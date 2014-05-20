/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 01:05:18 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/16 23:36:58 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_c(int x, int next)
{
	int		i;

	i = 1;
	while (i < x && x > 0)
	{
		ft_putchar(' ');
		i++;
	}
	if (!x)
		x++;
	if (ft_isascii(next))
		ft_putchar(next);
	i = -1;
	while (i > x && x < 0)
	{
		ft_putchar(' ');
		i--;
	}
	return (ft_abs(x));
}

int				ft_all(const char *str, int *i, va_list ap)
{
	int		x;
	int		next;

	x = va_arg(ap, int);
	next = va_arg(ap, int);
	if (str[*i + 2] == 'c')
	{
		(*i)++;
		return (print_c(x, next) - 3);
	}
	else if (str[*i + 3] == 'c')
	{
		*i += 2;
		print_c(0, next);
		return (-3);
	}
	return (ft_all_2(i, str, x, next));
}

int				ft_all_2(int *i, const char *str, int x, int next)
{
	int		length;
	char	c;

	length = 0;
	c = ' ';
	length -= 3;
	if (str[*i + 1] == '.')
	{
		(*i)++;
		length--;
		c = '0';
	}
	if (!(x == 0 && next == 0 && str[*i] == '.'))
	{
		if (ft_abs(x) <= (int)ft_strlen(ft_itoa(next)))
			length += ft_putstr(ft_itoa(next));
		else if (x < 0)
			length += first_else(x, next, str[*i], c);
		else
			length += second_else(x, next, str[*i], c);
	}
	(*i)++;
	return (length);
}

int				first_else(int x, int next, char str, char c)
{
	int		length;
	int		a;

	a = ft_putstr(ft_itoa(next));
	x = ft_abs(x) - a;
	length = a;
	if (str != '.')
	{
		a = 0;
		while (a < x)
		{
			ft_putchar(c);
			a++;
		}
		length += x;
	}
	return (length);
}

int				second_else(int x, int next, char str, char c)
{
	int		length;
	int		a;

	length = 0;
	a = 0;
	if (next < 0 && str == '.')
	{
		length++;
		ft_putchar('-');
		next = ft_abs(next);
	}
	x -= ft_strlen(ft_itoa(next));
	while (a < x)
	{
		ft_putchar(c);
		a++;
	}
	length += ft_putstr(ft_itoa(next)) + x;
	return (length);
}
