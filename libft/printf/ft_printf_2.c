/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 05:13:59 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/25 21:42:09 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_cond_1(const char *str, int *i, va_list ap, int x)
{
	int		length;

	length = 0;
	if (str[x] == 'd' || str[x] == 'i')
	{
		(*i)--;
		length += ft_point(str, i, va_arg(ap, int), " ") + 1;
	}
	else if (str[x] == 'c')
		length += ft_cond_1c(length, str, i, ap);
	return (length);
}

int		ft_cond_1c(int length, const char *str, int *i, va_list ap)
{
	int		x;

	length--;
	x = ft_atoi(&str[*i + 1]);
	while (x > 1)
	{
		x--;
		ft_putchar(' ');
		length++;
	}
	while (str[*i + 1] != 'c')
	{
		length--;
		(*i)++;
	}
	ft_putchar(va_arg(ap, int));
	return (length);
}

int		ft_cond_2(const char *str, int *i, va_list ap)
{
	int		x;
	int		length;

	length = 0;
	x = *i + 2;
	while (str[x] >= 48 && str[x] <= 57)
		x++;
	if (str[x] == 'c')
	{
		length--;
		while (str[*i + 1] != 'c')
		{
			length--;
			(*i)++;
		}
		ft_putchar(va_arg(ap, int));
	}
	else
	{
		x = va_arg(ap, int);
		if (x < 0 && x != -2147483648)
			length += ft_putstr("-");
		length += ft_point(str, i, ft_abs(x), "0");
	}
	return (length);
}

int		ft_cond_3c(const char *str, int *i, int x)
{
	if (x < 0)
		ft_putchar('-');
	else
		ft_putchar('+');
	return (ft_point(str, i, ft_abs(x), "0"));
}

int		ft_cond_3(const char *str, int *i, int x)
{
	int		length;
	char	*ch;

	length = 0;
	if (!(x == 0 && str[*i] == '.'))
	{
		if (str[*i + 1] == ' ' || str[*i + 1] == '+')
		{
			(*i)++;
			if (str[*i + 1] == '.')
				return (ft_cond_3c(str, i, x));
			if (x >= 0)
				ft_putchar(str[*i]);
			else
				length--;
		}
		ch = ft_itoa(x);
		length += ft_strlen(ch) - 2;
		free(ch);
		ft_putnbr(x);
	}
	else
		length -= 2;
	return (length);
}
