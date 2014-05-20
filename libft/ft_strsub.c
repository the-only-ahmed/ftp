/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:16:48 by jyim              #+#    #+#             */
/*   Updated: 2013/11/25 22:28:40 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char*) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[i] = s[start];
		start++;
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
