/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:15:09 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:49:07 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_neg(int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_neg(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
		ft_putnbr_neg(n);
}
