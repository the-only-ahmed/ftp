/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:22:44 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:41:55 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dest;
	char			*src;
	unsigned char	chr;

	dest = (char *)s1;
	src = (char *)s2;
	chr = (unsigned char)c;
	while (n)
	{
		if ((*dest = *src) == chr)
			return (++dest);
		n--;
		dest++;
		src++;
	}
	return (NULL);
}
