/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:56:27 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/16 23:38:34 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strdup(const char *s1)
{
	char	*copy;
	int		length;
	int		i;

	length = 0;
	while (s1[length] != '\0')
		length++;
	copy = (char*)malloc(sizeof(*s1) * (length + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i <= length)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
