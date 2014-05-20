/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uput2long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:32:30 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/23 21:02:29 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*reverse(unsigned long long n)
{
	int		rev;
	char	*str;
	char	*ch;

	if (n == 0)
		return ("0");
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	while (n > 0)
	{
		rev = n % 10;
		if (rev >= 10)
		{
			ch = (char*)malloc(sizeof(char) * 2);
			ch[0] = rev + 87;
			ch[1] = '\0';
		}
		else
			ch = ft_itoa(rev);
		str = ft_strjoin(ch, str);
		n /= 10;
	}
	free(ch);
	return (str);
}

int				ft_putunsigned_2long(unsigned long long n)
{
	int		a;
	char	*str;

	a = 0;
	str = reverse(n);
	a = ft_putstr(str);
	return (a);
}
