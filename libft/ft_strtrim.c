/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:31:09 by jyim              #+#    #+#             */
/*   Updated: 2013/12/02 15:41:00 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	int		new;
	char	*dest;

	i = 0;
	end = ft_strlen(s);
	new = 0;
	dest = (char *)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[end] == '\0' || s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	while (i <= end)
	{
		dest[new] = s[i];
		new++;
		i++;
	}
	dest[new] = '\0';
	return (dest);
}
