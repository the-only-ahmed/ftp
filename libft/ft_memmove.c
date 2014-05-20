/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:37:09 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:42:26 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = s1;
	src = s2;
	i = n - 1;
	if (s2 <= s1)
	{
		while (n > 0)
		{
			dest[i] = src[i];
			i--;
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
