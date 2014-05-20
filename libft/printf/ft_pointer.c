/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:09:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/04/27 22:53:51 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printpointeur(void *p)
{
	unsigned long	div;
	unsigned long	n;
	char			*lst;
	int				length;

	div = 1;
	length = 0;
	n = (unsigned long)p;
	lst = malloc(sizeof(char) * 16);
	if (!lst)
		return (ft_putstr("0"));
	lst = "0123456789abcdef";
	while (n / div > (16 - 1))
		div *= 16;
	while (div >= 1)
	{
		ft_putchar(lst[0 + n / div % 16]);
		div /= 16;
		length++;
	}
	return (length);
}

char	*printpointeur(void *p, unsigned long div)
{
	unsigned long	n;
	char			*lst;
	char			*word;
	int				i;

	n = (unsigned long)p;
	word = ft_strnew(0);
	i = 0;
	lst = malloc(sizeof(char) * 16);
	if (!lst)
	{
		word = ft_strdup("0");
		return (word);
	}
	lst = "0123456789abcdef";
	while (n / div > (16 - 1))
		div *= 16;
	while (div >= 1)
	{
		word[i] = lst[0 + n / div % 16];
		i++;
		div /= 16;
	}
	word[i] = '\0';
	return (word);
}
