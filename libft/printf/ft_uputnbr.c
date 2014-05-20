/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:28:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 12:45:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ch_reverse(int rev, int x)
{
	char	*ch;

	if (rev >= 10)
	{
		ch = (char*)malloc(sizeof(char) * 2);
		ch[0] = rev + x;
		ch[1] = '\0';
	}
	else
		ch = ft_itoa(rev);
	return (ch);
}

static char		*reverse(unsigned int n, int base)
{
	int		rev;
	char	*str;
	char	*ch;
	int		x;

	x = 87;
	if (base == 61)
	{
		base = 16;
		x = 55;
	}
	if (n == 0)
		return ("0");
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	while (n > 0)
	{
		rev = n % base;
		ch = ch_reverse(rev, x);
		str = ft_strjoin(ch, str);
		n /= base;
	}
	free(ch);
	return (str);
}

int				ft_putunsigned_int(unsigned int n, int base)
{
	int		a;
	char	*str;

	a = 0;
	if (n == 4294967294 && base == 10)
		return (ft_putstr("4294967294"));
	else if (n == 4294967295 && base == 10)
		return (ft_putstr("4294967295"));
	else if ((int)n < 0)
		n += 4294967296;
	str = reverse(n, base);
	a = ft_putstr(str);
	return (a);
}
