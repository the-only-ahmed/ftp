/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:06:47 by jyim              #+#    #+#             */
/*   Updated: 2013/12/02 15:38:53 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src2;
	size_t		size2;
	size_t		len;
	char		*dst2;

	len = size;
	dst2 = dst;
	src2 = src;
	size2 = size;
	while (*dst2 != '\0' && size2-- > 0)
		dst2++;
	len = dst2 - dst;
	size2 = size - len;
	if (size2 == 0)
		return (len + ft_strlen(src2));
	while (*src2 != '\0')
	{
		if (size2-- > 1)
		{
			*dst2++ = *src2;
		}
		src2++;
	}
	*dst2 = '\0';
	return (len + (src2 - src));
}
