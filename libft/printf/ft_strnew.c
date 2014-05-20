/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:42:00 by jyim              #+#    #+#             */
/*   Updated: 2014/03/27 11:12:44 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest)
	{
		ft_bzero(dest, (size + 1));
		return (dest);
	}
	return (NULL);
}
